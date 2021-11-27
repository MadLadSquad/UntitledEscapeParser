#pragma once

namespace Sequences
{
    namespace Colours
    {
        namespace Foreground
        {
            constexpr unsigned char DefaultColour = 39;    // Standard terminal foreground colours
            constexpr unsigned char Black = 30;            // Standard terminal foreground colours
            constexpr unsigned char Red = 31;              // Standard terminal foreground colours
            constexpr unsigned char Green = 32;            // Standard terminal foreground colours
            constexpr unsigned char Yellow = 33;           // Standard terminal foreground colours
            constexpr unsigned char Blue = 34;             // Standard terminal foreground colours
            constexpr unsigned char Magenta = 35;          // Standard terminal foreground colours
            constexpr unsigned char Cyan = 36;             // Standard terminal foreground colours
            constexpr unsigned char LightGrey = 37;        // Standard terminal foreground colours
            constexpr unsigned char DarkGrey = 90;         // Standard terminal foreground colours
            constexpr unsigned char LightRed = 91;         // Standard terminal foreground colours
            constexpr unsigned char LightGreen = 92;       // Standard terminal foreground colours
            constexpr unsigned char LightYellow = 93;      // Standard terminal foreground colours
            constexpr unsigned char LightBlue = 94;        // Standard terminal foreground colours
            constexpr unsigned char LightMagenta = 95;     // Standard terminal foreground colours
            constexpr unsigned char LightCyan = 96;        // Standard terminal foreground colours
            constexpr unsigned char White = 97;            // Standard terminal foreground colours
        }
        namespace Background
        {
            constexpr unsigned char DefaultColour = 49;    // Standard terminal background colours
            constexpr unsigned char Black = 40;            // Standard terminal background colours
            constexpr unsigned char Red = 41;              // Standard terminal background colours
            constexpr unsigned char Green = 42;            // Standard terminal background colours
            constexpr unsigned char Yellow = 43;           // Standard terminal background colours
            constexpr unsigned char Blue = 44;             // Standard terminal background colours
            constexpr unsigned char Magenta = 45;          // Standard terminal background colours
            constexpr unsigned char Cyan = 46;             // Standard terminal background colours
            constexpr unsigned char LightGrey = 47;        // Standard terminal background colours
            constexpr unsigned char DarkGrey = 100;        // Standard terminal background colours
            constexpr unsigned char LightRed = 101;        // Standard terminal background colours
            constexpr unsigned char LightGreen = 102;      // Standard terminal background colours
            constexpr unsigned char LightYellow = 103;     // Standard terminal background colours
            constexpr unsigned char LightBlue = 104;       // Standard terminal background colours
            constexpr unsigned char LightMagenta = 105;    // Standard terminal background colours
            constexpr unsigned char LightCyan = 106;       // Standard terminal background colours
            constexpr unsigned char White = 107;           // Standard terminal background colours
        }
    }
    namespace ColourSeparators
    {
        constexpr unsigned char Foreground = 38;
        constexpr unsigned char Background = 49;
        constexpr unsigned char Define256Colour = 5;
        constexpr unsigned char DefineTrueColour = 2;
        constexpr unsigned char ColourEscapeEnd = 'm';
        constexpr unsigned char BeginColourSequence = '[';
    }
    namespace Attributes
    {
        constexpr unsigned char AttributeSeparator = ';';
        constexpr unsigned char AllReset = 0;

        constexpr unsigned char Bold = 1;
        constexpr unsigned char Dim = 2;
        constexpr unsigned char Italic = 3;             // Not widely supported
        constexpr unsigned char Underlined = 4;
        constexpr unsigned char Blink = 5;
        constexpr unsigned char RapidBlink = 6;         // Not widely supported
        [[maybe_unused]] constexpr unsigned char Reverse = 7;
        constexpr unsigned char Invert = 7;
        constexpr unsigned char Hidden =  8;
        [[maybe_unused]] constexpr unsigned char Password =  8;
        constexpr unsigned char CrossedOut = 9;         // Not widely supported
        constexpr unsigned char PrimaryFont = 10;       // Most terminals set 11-19 as secondary fonts
        constexpr unsigned char AlternativeFont1 = 11;  // Most terminals set 11-19 as secondary fonts
        constexpr unsigned char AlternativeFont2 = 12;  // Most terminals set 11-19 as secondary fonts
        constexpr unsigned char AlternativeFont3 = 13;  // Most terminals set 11-19 as secondary fonts
        constexpr unsigned char AlternativeFont4 = 14;  // Most terminals set 11-19 as secondary fonts
        constexpr unsigned char AlternativeFont5 = 15;  // Most terminals set 11-19 as secondary fonts
        constexpr unsigned char AlternativeFont6 = 16;  // Most terminals set 11-19 as secondary fonts
        constexpr unsigned char AlternativeFont7 = 17;  // Most terminals set 11-19 as secondary fonts
        constexpr unsigned char AlternativeFont8 = 18;  // Most terminals set 11-19 as secondary fonts
        constexpr unsigned char AlternativeFont9 = 19;  // Most terminals set 11-19 as secondary fonts
        constexpr unsigned char Fraktur = 20;

        constexpr unsigned char Framed = 51;
        constexpr unsigned char Encircled = 52;
        constexpr unsigned char Overlined = 53;
        constexpr unsigned char ResetFramedAndEncircled = 54;
        constexpr unsigned char ResetOverlined = 55;

        constexpr unsigned char IdeogramUnderline = 60;        // Hardly ever supported
        constexpr unsigned char IdeogramDoubleUnderline = 61;  // Hardly ever supported
        constexpr unsigned char IdeogramOverline = 62;         // Hardly ever supported
        constexpr unsigned char IdeogramDoubleOverline = 63;   // Hardly ever supported
        constexpr unsigned char IdeogramStressMarking = 64;    // Hardly ever supported
        constexpr unsigned char ResetIdeograms = 65;           // Hardly ever supported

        constexpr unsigned char ResetBold = 21;
        constexpr unsigned char ResetDim = 22;
        constexpr unsigned char ResetItalic = 23;                       // Not widely supported
        [[maybe_unused]] constexpr unsigned char ResetFraktur = 23;     // Not widely supported
        constexpr unsigned char ResetUnderlined = 24;
        constexpr unsigned char ResetBlink = 25;
        constexpr unsigned char ResetReverse = 27;
        [[maybe_unused]] constexpr unsigned char ResetInvert = 27;
        constexpr unsigned char ResetHidden = 28;
        [[maybe_unused]] constexpr unsigned char ResetPassword = 28;
        constexpr unsigned char ResetCrossedOut = 29;                   // Not widely supported
    }
    namespace EraseTypes
    {
        constexpr unsigned char EraseType1 = 'J';
        constexpr unsigned char EraseType2 = 'K';
    }
    namespace CursorMovement
    {
        constexpr unsigned char CursorH = 'H';
        constexpr unsigned char Cursorf = 'f';
        constexpr unsigned char CursorA = 'A';
        constexpr unsigned char CursorB = 'B';
        constexpr unsigned char CursorC = 'C';
        constexpr unsigned char CursorD = 'D';
        constexpr unsigned char CursorE = 'E';
        constexpr unsigned char CursorF = 'F';
        constexpr unsigned char CursorG = 'G';
        constexpr unsigned char Cursorn = 'n';
        constexpr unsigned char Cursors = 's';
        constexpr unsigned char Cursoru = 'u';
    }
    namespace ScreenModes
    {
        constexpr unsigned char ScreenModeTerminator = 'h';
        constexpr unsigned char ScreenModeTerminatorReset = 'l';
        constexpr unsigned char ScreenMode0 = 0;                    // 40 x 25 monochrome (text)
        constexpr unsigned char ScreenMode1 = 1;                    // 40 x 25 color (text)
        constexpr unsigned char ScreenMode2 = 2;                    // 80 x 25 monochrome (text)
        constexpr unsigned char ScreenMode3 = 3;                    // 80 x 25 color (text)
        constexpr unsigned char ScreenMode4 = 4;                    // 320 x 200 4-color (graphics)
        constexpr unsigned char ScreenMode5 = 5;                    // 320 x 200 monochrome (graphics)
        constexpr unsigned char ScreenMode6 = 6;                    // 640 x 200 monochrome (graphics)
        constexpr unsigned char ScreenMode7 = 7;                    // Enables line wrapping
        constexpr unsigned char ScreenMode13 = 13;                  // 320 x 200 color (graphics)
        constexpr unsigned char ScreenMode14 = 14;                  // 640 x 200 color (16-color graphics)
        constexpr unsigned char ScreenMode15 = 15;                  // 640 x 350 monochrome (2-color graphics)
        constexpr unsigned char ScreenMode16 = 16;                  // 640 x 350 color (16-color graphics)
        constexpr unsigned char ScreenMode17 = 17;                  // 640 x 480 monochrome (2-color graphics)
        constexpr unsigned char ScreenMode18 = 18;                  // 640 x 480 color (16-color graphics)
        constexpr unsigned char ScreenMode19 = 19;                  // 320 x 200 color (256-color graphics)

        constexpr unsigned char PrivateModeCursor = 25;             // Enabled/Disabled depending on the terminator
        constexpr unsigned char PrivateModeScreen = 47;             // Enabled/Disabled depending on the terminator
        constexpr unsigned char PrivateModeAlternativeBuffer = 255; // Actual value here is 1049 but to be economical we're going to keep 255 and multiply by 4 then add 49 to get the right number
    }
}