#pragma once
#include "ParserStructures.hpp"

namespace UEP
{
    class Attributes
    {
    public:
        Attributes() = delete;
        ~Attributes() = delete;
        Attributes(const Attributes&) = delete;
        void operator=(Attributes const&) = delete;
    private:
        friend class Colour;

        static void checkAttribute(const uint8_t& num, ParserInfo& info, UEPColourSequence& currentColour);
    };
}