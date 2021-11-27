#pragma once
#include "ParserStructures.hpp"

namespace UEP
{
    class Cursor
    {
    public:
        Cursor() = delete;
        ~Cursor() = delete;
        Cursor(const Cursor&) = delete;
        void operator=(Cursor const&) = delete;
    private:
        friend class Parser;

        static void position(const std::string& accumulatedString, std::string& sequence, std::string& buffer, size_t& index, UEPColourSequence& currentColour, ParserInfo& info);

        static void up(const std::string& accumulatedString, std::string& sequence, std::string& buffer, size_t& index, UEPColourSequence& currentColour, ParserInfo& info);
        static void down(const std::string& accumulatedString, std::string& sequence, std::string& buffer, size_t& index, UEPColourSequence& currentColour, ParserInfo& info);
        static void right(const std::string& accumulatedString, std::string& sequence, std::string& buffer, size_t& index, UEPColourSequence& currentColour, ParserInfo& info);
        static void left(const std::string& accumulatedString, std::string& sequence, std::string& buffer, size_t& index, UEPColourSequence& currentColour, ParserInfo& info);

        static void lineBeginDown(const std::string& accumulatedString, std::string& sequence, std::string& buffer, size_t& index, UEPColourSequence& currentColour, ParserInfo& info);
        static void lineBeginUp(const std::string& accumulatedString, std::string& sequence, std::string& buffer, size_t& index, UEPColourSequence& currentColour, ParserInfo& info);

        static void toColumn(const std::string& accumulatedString, std::string& sequence, std::string& buffer, size_t& index, UEPColourSequence& currentColour, ParserInfo& info);
        static void requestCursorPosition(const std::string& accumulatedString, std::string& sequence, std::string& buffer, size_t& index, UEPColourSequence& currentColour, ParserInfo& info);

        static void oneLineUp(const std::string& accumulatedString, std::string& sequence, std::string& buffer, size_t& index, UEPColourSequence& currentColour, ParserInfo& info);

        static void saveCursorPosition(const std::string& accumulatedString, std::string& sequence, std::string& buffer, size_t& index, UEPColourSequence& currentColour, ParserInfo& info);
        static void restoreCursorPosition(const std::string& accumulatedString, std::string& sequence, std::string& buffer, size_t& index, UEPColourSequence& currentColour, ParserInfo& info);
    };
}