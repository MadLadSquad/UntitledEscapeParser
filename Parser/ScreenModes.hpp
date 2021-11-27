#pragma once
#include "ParserStructures.hpp"

namespace UEP
{
    class ScreenMode
    {
    public:
        ScreenMode() = delete;
        ~ScreenMode() = delete;
        ScreenMode(const ScreenMode&) = delete;
        void operator=(ScreenMode const&) = delete;
    private:
        friend class Parser;

        static void reset(const std::string& accumulatedString, std::string& sequence, std::string& buffer, size_t& index, UEPColourSequence& currentColour, ParserInfo& info);
        static void normal(const std::string& accumulatedString, std::string& sequence, std::string& buffer, size_t& index, UEPColourSequence& currentColour, ParserInfo& info);
    };
}