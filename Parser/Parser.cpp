#include "Parser.hpp"
#include "Utilities.hpp"
#include "Colour.hpp"
#include "Sequences.hpp"
#include "Erase.hpp"
#include "Cursor.hpp"
#include "ScreenModes.hpp"

void UEP::Parser::parse(std::string& string)
{
    bool accumulating = true;
    std::string buffer;
    std::string currentSequence;

    for (size_t i = 0; i < string.size(); i++)
    {
        switch (string[i])
        {
        case '\n':
            info.newline(buffer);
            removeSingleCharacterSequence(i, buffer, accumulating);
            break;
        case '\a':
            info.bell(buffer);
            removeSingleCharacterSequence(i, buffer, accumulating);
            break;
        case '\b':
            info.backspace(buffer);
            removeSingleCharacterSequence(i, buffer, accumulating);
            break;
        case '\f':
            info.formFeed(buffer);
            removeSingleCharacterSequence(i, buffer, accumulating);
            break;
        case '\r':
            info.carriageReturn(buffer);
            removeSingleCharacterSequence(i, buffer, accumulating);
            break;
        case '\t':
            info.tab(buffer);
            removeSingleCharacterSequence(i, buffer, accumulating);
            break;
        case '\v':
            info.verticalTab(buffer);
            removeSingleCharacterSequence(i, buffer, accumulating);
            break;
        case '\x1B': // This also covers \033 \u001b and \x1B
            if (string[i + 1] == '[')
                checkSequenceType(buffer, currentSequence, string, i);
                //Colour::parseColourSequence(buffer, currentSequence, string, i, currentColour, info);
            break;
        default:
            buffer += string[i];
            break;
        }
    }
}

UEP::Parser::Parser(std::string& string, ParserInfo parserInfo)
    : info(std::move(parserInfo))
{
    parse(string);
}

void UEP::Parser::checkSequenceType(const std::string& accumulatedString, std::string& sequence, std::string& buffer, size_t& index)
{
    for (size_t i = index; i < buffer.size(); i++)
    {
        sequence += buffer[i];

        switch (buffer[i])
        {
        case Sequences::ColourSeparators::ColourEscapeEnd:
            index = i + 1;
            Colour::parseColourSequence(accumulatedString, sequence, currentColour, info);
            break;
        case Sequences::EraseTypes::EraseType1:
            index += i + 1;
            Erase::erase(accumulatedString, sequence, buffer, index, currentColour, info);
            break;
        case Sequences::EraseTypes::EraseType2:
            index += i + 1;
            Erase::erase2(accumulatedString, sequence, buffer, index, currentColour, info);
            break;
        case Sequences::ScreenModes::ScreenModeTerminator:
            index += i + 1;
            ScreenMode::normal(accumulatedString, sequence, buffer, index, currentColour, info);
            break;
        case Sequences::ScreenModes::ScreenModeTerminatorReset:
            index += i + 1;
            ScreenMode::reset(accumulatedString, sequence, buffer, index, currentColour, info);
            break;
        case Sequences::CursorMovement::CursorH:
            index += i + 1;
            Cursor::position(accumulatedString, sequence, buffer, index, currentColour, info);
            break;
        case Sequences::CursorMovement::Cursorf:
            index += i + 1;
            Cursor::position(accumulatedString, sequence, buffer, index, currentColour, info);
            break;
        case Sequences::CursorMovement::CursorA:
            index += i + 1;
            Cursor::up(accumulatedString, sequence, buffer, index, currentColour, info);
            break;
        case Sequences::CursorMovement::CursorB:
            index += i + 1;
            Cursor::down(accumulatedString, sequence, buffer, index, currentColour, info);
            break;
        case Sequences::CursorMovement::CursorC:
            index += i + 1;
            Cursor::right(accumulatedString, sequence, buffer, index, currentColour, info);
            break;
        case Sequences::CursorMovement::CursorD:
            index += i + 1;
            Cursor::left(accumulatedString, sequence, buffer, index, currentColour, info);
            break;
        case Sequences::CursorMovement::CursorE:
            index += i + 1;
            Cursor::lineBeginDown(accumulatedString, sequence, buffer, index, currentColour, info);
            break;
        case Sequences::CursorMovement::CursorF:
            index += i + 1;
            Cursor::lineBeginUp(accumulatedString, sequence, buffer, index, currentColour, info);
            break;
        case Sequences::CursorMovement::CursorG:
            index += i + 1;
            Cursor::toColumn(accumulatedString, sequence, buffer, index, currentColour, info);
            break;
        case Sequences::CursorMovement::Cursorn:
            index += i + 1;
            Cursor::requestCursorPosition(accumulatedString, sequence, buffer, index, currentColour, info);
            break;
        case Sequences::CursorMovement::Cursors:
            index += i + 1;
            Cursor::saveCursorPosition(accumulatedString, sequence, buffer, index, currentColour, info);
            break;
        case Sequences::CursorMovement::Cursoru:
            Cursor::restoreCursorPosition(accumulatedString, sequence, buffer, index, currentColour, info);
            break;
        }
    }
}
