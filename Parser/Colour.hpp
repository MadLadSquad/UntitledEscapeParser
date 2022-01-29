#pragma once
#include "ParserStructures.hpp"
#include "Attributes.hpp"

// If we're using custom 256 colours we use this macro to fix compiler errors since depending on the mode
// it's either a normal or static member
#ifdef UEP_CUSTOM_256
    #define UEP_COLOUR_ACCESS ParserInfo.colours256
#else
    #define UEP_COLOUR_ACCESS ParserInfo::colours256
#endif

namespace UEP
{
    class Colour
    {
    public:
        Colour() = delete;
        ~Colour() = delete;
        Colour(const Colour&) = delete;
        void operator=(Colour const&) = delete;
    private:
        friend class Parser;

        static void parseColourSequence(const std::string& accumulatedString, std::string& sequence, UEPColourSequence& currentColour, ParserInfo& info);
        static void extractNumbersOutOfSequence(std::vector<uint8_t>& numbers, const std::string& sequence);
    };
}