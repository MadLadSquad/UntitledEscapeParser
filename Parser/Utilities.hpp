#pragma once
#include "ParserStructures.hpp"
#include <string>

namespace UEP
{
    UEP::UEPTrueColourF colourToFloat(const UEPTrueColour& colour);
    void removeSingleCharacterSequence(std::string& base, size_t& index, std::string& str, bool& accumulating);
}