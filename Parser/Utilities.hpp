#pragma once
#include "ParserStructures.hpp"
#include <string>

namespace UEP
{
    [[maybe_unused]] UEP::UEPTrueColourF colourToFloat(const UEPTrueColour& colour);
    void removeSingleCharacterSequence(size_t& index, std::string& str, bool& accumulating);
}