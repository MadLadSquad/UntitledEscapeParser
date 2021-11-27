#pragma once
#include "ParserStructures.hpp"
#include "Attributes.hpp"

#include <iostream>

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