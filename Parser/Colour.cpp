#include "Colour.hpp"
#include "Sequences.hpp"

void UEP::Colour::parseColourSequence(const std::string& accumulatedString, std::string& sequence, UEP::UEPColourSequence& currentColour, UEP::ParserInfo& info)
{
    std::vector<uint8_t> numbers;

    extractNumbersOutOfSequence(numbers, sequence);

    for (uint32_t i = 0; i < numbers.size(); i++)
    {
        // 256 foreground colour
        if (numbers[i] == Sequences::ColourSeparators::Define256Colour && i > 0 && (i + 1) < numbers.size() && numbers[i - 1] == Sequences::ColourSeparators::Foreground)
        {
            currentColour.foregroundColour = ParserInfo::colours256[numbers[i + 1]];
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
            Attributes::checkAttribute(numbers[i], info, currentColour);
    }
    info.colour(accumulatedString, currentColour);
}

void UEP::Colour::extractNumbersOutOfSequence(std::vector<uint8_t>& numbers, const std::string& sequence)
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