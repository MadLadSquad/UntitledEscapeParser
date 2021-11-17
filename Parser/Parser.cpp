#include "Parser.hpp"
#include "Sequences.hpp"
#include "Utilities.hpp"

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
            removeSingleCharacterSequence(string, i, buffer, accumulating);
            break;
        case '\a':
            info.bell(buffer);
            removeSingleCharacterSequence(string, i, buffer, accumulating);
            break;
        case '\b':
            info.backspace(buffer);
            removeSingleCharacterSequence(string, i, buffer, accumulating);
            break;
        case '\f':
            info.formFeed(buffer);
            removeSingleCharacterSequence(string, i, buffer, accumulating);
            break;
        case '\r':
            info.carriageReturn(buffer);
            removeSingleCharacterSequence(string, i, buffer, accumulating);
            break;
        case '\t':
            info.tab(buffer);
            removeSingleCharacterSequence(string, i, buffer, accumulating);
            break;
        case '\v':
            info.verticalTab(buffer);
            removeSingleCharacterSequence(string, i, buffer, accumulating);
            break;
        case '\x1B': // This also covers \033 \u001b and \x1B
            if (string[i + 1] == '[')
                parseColourSequence(buffer, currentSequence, string, i);
            break;
        }
    }
}

UEP::Parser::Parser(std::string& string, ParserInfo parserInfo)
    : info(std::move(parserInfo))
{
    parse(string);
}

void UEP::Parser::parseColourSequence(const std::string& accumulatedString, std::string& sequence, std::string& buffer, size_t& index)
{
    for (size_t i = index; i < buffer.size(); i++)
    {
        sequence += buffer[i];
        if (buffer[i] == Sequences::ColourSeparators::ColourEscapeEnd)
        {
            buffer.erase(buffer.begin() + (int64_t)index, buffer.begin() + (int64_t)i + 1);
            break;
        }
    }
    index--;

    std::vector<uint8_t> numbers;

    {
        std::string accumulatedNumber;
        for (const auto& a : sequence)
        {
            if (a == Sequences::Attributes::AttributeSeparator)
            {
                numbers.emplace_back(static_cast<uint8_t>(std::stoi(accumulatedNumber)));
                accumulatedNumber.clear();
            }
            else if (a == Sequences::ColourSeparators::ColourEscapeEnd)
            {
                numbers.emplace_back(static_cast<uint8_t>(std::stoi(accumulatedNumber)));
                accumulatedNumber.clear();
                break;
            }
            else if (a != Sequences::ColourSeparators::BeginColourSequence && a != '\x1B')
                accumulatedNumber += a;
        }
    }

    for (uint32_t i = 0; i < numbers.size(); i++)
    {
        // 256 foreground colour
        if (numbers[i] == Sequences::ColourSeparators::Define256Colour && i > 0 && (i + 1) < numbers.size() && numbers[i - 1] == Sequences::ColourSeparators::Foreground)
        {
            currentColour.foregroundColour = ParserInfo::colours256[i + 1];
            i++;
        }
        else if (numbers[i] == Sequences::ColourSeparators::Define256Colour && i > 0 && (i + 1) < numbers.size() && numbers[i - 1] == Sequences::ColourSeparators::Background) // 256 background colour
        {
            currentColour.backgroundColour = ParserInfo::colours256[numbers[i + 1]];
            i++;
        }
        else if (numbers[i] == Sequences::ColourSeparators::Define256Colour && (i == 0 || (numbers[i - 1] == Sequences::ColourSeparators::Foreground || numbers[i - 1] == Sequences::ColourSeparators::Background))) // Blink attribute
            currentColour.attributes[Sequences::Attributes::Blink] = true;
        else if (numbers[i] == Sequences::ColourSeparators::DefineTrueColour && i > 0 && (i + 3) < numbers.size() && numbers[i - 1] == Sequences::ColourSeparators::Foreground) // TrueColour foreground colour
        {
            currentColour.foregroundColour = { numbers[i + 1], numbers[i + 2], numbers[i + 3], 255 };
            i += 3;
        }
        else if (numbers[i] == Sequences::ColourSeparators::DefineTrueColour && i > 0 && (i + 3) < numbers.size() && numbers[i - 1] == Sequences::ColourSeparators::Background) // TrueColour foreground colour
        {
            currentColour.backgroundColour = { numbers[i + 1], numbers[i + 2], numbers[i + 3], 255 };
            i += 3;
        }
        else if (numbers[i] == Sequences::ColourSeparators::DefineTrueColour && (i == 0 || (numbers[i - 1] == Sequences::ColourSeparators::Foreground || numbers[i - 1] == Sequences::ColourSeparators::Background)))
            currentColour.attributes[Sequences::Attributes::Dim] = true;
        else if (i == 0 || (numbers[i - 1] == Sequences::ColourSeparators::Foreground || numbers[i - 1] == Sequences::ColourSeparators::Background))
        {
            // Parse all attribute sequences
            switch (numbers[i])
            {
            case Sequences::Attributes::AllReset:
                for (auto& a : currentColour.attributes)
                    a = false;
                break;
            case Sequences::Attributes::Bold:
                currentColour.attributes[Sequences::Attributes::Bold] = true;
                break;
            case Sequences::Attributes::Dim:
                currentColour.attributes[Sequences::Attributes::Dim] = true;
                break;
            case Sequences::Attributes::Italic:
                currentColour.attributes[Sequences::Attributes::Italic] = true;
                break;
            case Sequences::Attributes::Underlined:
                currentColour.attributes[Sequences::Attributes::Underlined] = true;
                break;
            case Sequences::Attributes::Blink:
                currentColour.attributes[Sequences::Attributes::Blink] = true;
                break;
            case Sequences::Attributes::RapidBlink:
                currentColour.attributes[Sequences::Attributes::RapidBlink] = true;
                break;
            case Sequences::Attributes::Invert:
                currentColour.attributes[Sequences::Attributes::Invert] = true;
                break;
            case Sequences::Attributes::Hidden:
                currentColour.attributes[Sequences::Attributes::Hidden] = true;
                break;
            case Sequences::Attributes::CrossedOut:
                currentColour.attributes[Sequences::Attributes::CrossedOut] = true;
                break;
            case Sequences::Attributes::PrimaryFont:
                currentColour.attributes[Sequences::Attributes::PrimaryFont] = true;
                break;
            case Sequences::Attributes::Fraktur:
                currentColour.attributes[Sequences::Attributes::Fraktur] = true;
                break;
            case Sequences::Attributes::Framed:
                currentColour.attributes[Sequences::Attributes::Framed] = true;
                break;
            case Sequences::Attributes::Encircled:
                currentColour.attributes[Sequences::Attributes::Encircled] = true;
                break;
            case Sequences::Attributes::Overlined:
                currentColour.attributes[Sequences::Attributes::Overlined] = true;
                break;
            case Sequences::Attributes::ResetFramedAndEncircled:
                currentColour.attributes[Sequences::Attributes::Framed] = false;
                currentColour.attributes[Sequences::Attributes::Encircled] = false;
                break;
            case Sequences::Attributes::ResetOverlined:
                currentColour.attributes[Sequences::Attributes::Overlined] = false;
                break;
            case Sequences::Attributes::IdeogramUnderline:
                currentColour.attributes[Sequences::Attributes::IdeogramUnderline] = true;
                break;
            case Sequences::Attributes::IdeogramDoubleUnderline:
                currentColour.attributes[Sequences::Attributes::IdeogramDoubleUnderline] = true;
                break;
            case Sequences::Attributes::IdeogramOverline:
                currentColour.attributes[Sequences::Attributes::IdeogramOverline] = true;
                break;
            case Sequences::Attributes::IdeogramDoubleOverline:
                currentColour.attributes[Sequences::Attributes::IdeogramDoubleOverline] = true;
                break;
            case Sequences::Attributes::IdeogramStressMarking:
                currentColour.attributes[Sequences::Attributes::IdeogramStressMarking] = true;
                break;
            case Sequences::Attributes::ResetIdeograms:
                currentColour.attributes[Sequences::Attributes::IdeogramStressMarking] = false;
                currentColour.attributes[Sequences::Attributes::IdeogramDoubleOverline] = false;
                currentColour.attributes[Sequences::Attributes::IdeogramOverline] = false;
                currentColour.attributes[Sequences::Attributes::IdeogramUnderline] = false;
                currentColour.attributes[Sequences::Attributes::IdeogramDoubleUnderline] = false;
                break;
            case Sequences::Attributes::ResetBold:
                currentColour.attributes[Sequences::Attributes::Bold] = false;
                break;
            case Sequences::Attributes::ResetDim:
                currentColour.attributes[Sequences::Attributes::Dim] = false;
                break;
            case Sequences::Attributes::ResetItalic:
                currentColour.attributes[Sequences::Attributes::Italic] = false;
                currentColour.attributes[Sequences::Attributes::Fraktur] = false;
                break;
            case Sequences::Attributes::ResetUnderlined:
                currentColour.attributes[Sequences::Attributes::Underlined] = false;
                break;
            case Sequences::Attributes::ResetBlink:
                currentColour.attributes[Sequences::Attributes::Blink] = false;
                break;
            case Sequences::Attributes::ResetReverse:
                currentColour.attributes[Sequences::Attributes::Invert] = false;
                break;
            case Sequences::Attributes::ResetHidden:
                currentColour.attributes[Sequences::Attributes::Hidden] = false;
                break;
            case Sequences::Attributes::ResetCrossedOut:
                currentColour.attributes[Sequences::Attributes::CrossedOut] = false;
                break;
            case Sequences::Colours::Foreground::DefaultColour:
                currentColour.foregroundColour = info.white;
                break;
            case Sequences::Colours::Foreground::Black:
                currentColour.foregroundColour = info.black;
                break;
            case Sequences::Colours::Foreground::Red:
                currentColour.foregroundColour = info.red;
                break;
            case Sequences::Colours::Foreground::Green:
                currentColour.foregroundColour = info.green;
                break;
            case Sequences::Colours::Foreground::Yellow:
                currentColour.foregroundColour = info.yellow;
                break;
            case Sequences::Colours::Foreground::Blue:
                currentColour.foregroundColour = info.blue;
                break;
            case Sequences::Colours::Foreground::Magenta:
                currentColour.foregroundColour = info.magenta;
                break;
            case Sequences::Colours::Foreground::Cyan:
                currentColour.foregroundColour = info.cyan;
                break;
            case Sequences::Colours::Foreground::LightGrey:
                currentColour.foregroundColour = info.lightgrey;
                break;
            case Sequences::Colours::Foreground::DarkGrey:
                currentColour.foregroundColour = info.grey;
                break;
            case Sequences::Colours::Foreground::LightRed:
                currentColour.foregroundColour = info.lightred;
                break;
            case Sequences::Colours::Foreground::LightGreen:
                currentColour.foregroundColour = info.lightgreen;
                break;
            case Sequences::Colours::Foreground::LightYellow:
                currentColour.foregroundColour = info.lightyellow;
                break;
            case Sequences::Colours::Foreground::LightBlue:
                currentColour.foregroundColour = info.lightblue;
                break;
            case Sequences::Colours::Foreground::LightMagenta:
                break;
            case Sequences::Colours::Foreground::LightCyan:
                currentColour.foregroundColour = info.lightcyan;
                break;
            case Sequences::Colours::Foreground::White:
                currentColour.foregroundColour = info.white;
                break;
            case Sequences::Colours::Background::DefaultColour:
                currentColour.backgroundColour = info.black;
                break;
            case Sequences::Colours::Background::Black:
                currentColour.backgroundColour = info.black;
                break;
            case Sequences::Colours::Background::Red:
                currentColour.backgroundColour = info.red;
                break;
            case Sequences::Colours::Background::Green:
                currentColour.backgroundColour = info.green;
                break;
            case Sequences::Colours::Background::Yellow:
                currentColour.backgroundColour = info.yellow;
                break;
            case Sequences::Colours::Background::Blue:
                currentColour.backgroundColour = info.blue;
                break;
            case Sequences::Colours::Background::Magenta:
                currentColour.backgroundColour = info.magenta;
                break;
            case Sequences::Colours::Background::Cyan:
                currentColour.backgroundColour = info.cyan;
                break;
            case Sequences::Colours::Background::LightGrey:
                currentColour.backgroundColour = info.lightgrey;
                break;
            case Sequences::Colours::Background::DarkGrey:
                currentColour.backgroundColour = info.grey;
                break;
            case Sequences::Colours::Background::LightRed:
                currentColour.backgroundColour = info.lightred;
                break;
            case Sequences::Colours::Background::LightGreen:
                currentColour.backgroundColour = info.lightgreen;
                break;
            case Sequences::Colours::Background::LightYellow:
                currentColour.backgroundColour = info.lightyellow;
                break;
            case Sequences::Colours::Background::LightBlue:
                currentColour.backgroundColour = info.lightblue;
                break;
            case Sequences::Colours::Background::LightMagenta:
                currentColour.backgroundColour = info.lightmagenta;
                break;
            case Sequences::Colours::Background::LightCyan:
                currentColour.backgroundColour = info.cyan;
                break;
            case Sequences::Colours::Background::White:
                currentColour.backgroundColour = info.white;
                break;
            case Sequences::Attributes::AlternativeFont1:
                currentColour.currentFont = 1;
                break;
            case Sequences::Attributes::AlternativeFont2:
                currentColour.currentFont = 2;
                break;
            case Sequences::Attributes::AlternativeFont3:
                currentColour.currentFont = 3;
                break;
            case Sequences::Attributes::AlternativeFont4:
                currentColour.currentFont = 4;
                break;
            case Sequences::Attributes::AlternativeFont5:
                currentColour.currentFont = 5;
                break;
            case Sequences::Attributes::AlternativeFont6:
                currentColour.currentFont = 6;
                break;
            case Sequences::Attributes::AlternativeFont7:
                currentColour.currentFont = 7;
                break;
            case Sequences::Attributes::AlternativeFont8:
                currentColour.currentFont = 8;
                break;
            case Sequences::Attributes::AlternativeFont9:
                currentColour.currentFont = 9;
                break;
            }
        }
    }
    info.colour(accumulatedString, currentColour);
}
