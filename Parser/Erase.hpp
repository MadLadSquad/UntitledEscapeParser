#pragma once
#include "ParserStructures.hpp"

namespace UEP
{
    class Erase
    {
    public:
        Erase() = delete;
        ~Erase() = delete;
        Erase(const Erase&) = delete;
        void operator=(Erase const&) = delete;
    private:
        friend class Parser;

        static void erase(const std::string& accumulatedString, std::string& sequence, std::string& buffer, size_t& index, UEP::UEPColourSequence& currentColour, UEP::ParserInfo& info);
        static void erase2(const std::string& accumulatedString, std::string& sequence, std::string& buffer, size_t& index, UEP::UEPColourSequence& currentColour, UEP::ParserInfo& info);
    };
}