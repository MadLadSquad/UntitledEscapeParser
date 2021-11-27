#include "Utilities.hpp"

[[maybe_unused]] UEP::UEPTrueColourF UEP::colourToFloat(const UEPTrueColour& colour)
{
    return { static_cast<float>(colour.r) / 255.0f, static_cast<float>(colour.g) / 255.0f, static_cast<float>(colour.b) / 255.0f, static_cast<float>(colour.a) / 255.0f };
}

void UEP::removeSingleCharacterSequence(size_t& index, std::string& str, bool& accumulating)
{
    str.clear();
    accumulating = false;
    index++;
}