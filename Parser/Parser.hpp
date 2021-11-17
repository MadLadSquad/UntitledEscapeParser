#pragma once
#include <string>
#include <vector>
#include <functional>
#include "ParserStructures.hpp"

namespace UEP
{
    class Parser
    {
    public:
        Parser() = delete;
        ~Parser() = default;
        Parser(const Parser&) = delete;
        void operator=(Parser const&) = delete;

        /**
         * @brief Given a string containing the sequences and a ParserInfo struct it will start
         * parsing the sequences in the string
         * @param string the string containing the sequences
         * @param parserInfo the info struct
         */
        Parser(std::string& string, ParserInfo  parserInfo);
    private:
        void parse(std::string& string);
        void parseColourSequence(const std::string& accumulatedString, std::string& sequence, std::string& buffer, size_t& index);

        // The current text colour and attribute structure
        UEPColourSequence currentColour{};
        // The current info struct
        const ParserInfo info;
    };
}