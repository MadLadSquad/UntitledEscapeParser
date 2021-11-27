#pragma once
#include <functional>

namespace UEP
{
    struct UEPTrueColour
    {
        uint8_t r;
        uint8_t g;
        uint8_t b;
        uint8_t a;
    };

    struct UEPTrueColourF
    {
        float r;
        float g;
        float b;
        float a;
    };

    struct UEPColourSequence;

    struct ParserInfo
    {
        std::function<void(const std::string&)> newline = [](const std::string&){};
        std::function<void(const std::string&)> bell = [](const std::string&){};
        std::function<void(const std::string&)> backspace = [](const std::string&){};
        std::function<void(const std::string&)> tab = [](const std::string&){};
        std::function<void(const std::string&)> formFeed = [](const std::string&){};
        std::function<void(const std::string&)> carriageReturn = [](const std::string&){};
        std::function<void(const std::string&)> verticalTab = [](const std::string&){};
        std::function<void(const std::string&, const UEPColourSequence&)> colour = [](const std::string&, const UEPColourSequence&){};

        UEPTrueColour black = { 0, 0, 0, 255 };
        UEPTrueColour white = { 255, 255, 255, 255 };

        UEPTrueColour lightred = { 255, 0, 0, 255 };
        UEPTrueColour lightgreen = { 0, 255, 0, 255 };
        UEPTrueColour lightyellow = { 255, 255, 0, 255 };
        UEPTrueColour lightblue = { 0, 0, 255, 255 };
        UEPTrueColour lightmagenta = { 255, 0, 255, 255 };
        UEPTrueColour lightcyan = { 0, 255, 255, 255 };
        UEPTrueColour lightgrey = { 194, 194, 194, 255 };

        UEPTrueColour red = { 128, 0, 0, 255 };
        UEPTrueColour green = { 0, 128, 0, 255 };
        UEPTrueColour yellow = { 255, 128, 0, 255 };
        UEPTrueColour blue = { 0, 0, 128, 255 };
        UEPTrueColour magenta = { 128, 0, 128, 255 };
        UEPTrueColour cyan = { 0, 128, 128, 255 };
        UEPTrueColour grey = { 64, 64, 64, 255 };

        // A table detailing all of those values can be found here https://www.4e00.com/tools/xterm-256-colors.html
        static constexpr const UEPTrueColour colours256[256] =
        {
            { 0, 0, 0, 255 },           // Name: Black
            { 128, 0, 0, 255 },         // Name: Maroon
            { 0, 128, 0, 255 },         // Name: Green
            { 128, 128, 0, 255 },       // Name: Olive
            { 0, 0, 128, 255 },         // Name: Navy
            { 128, 0, 128, 255 },       // Name: Purple
            { 0, 128, 128, 255 },       // Name: Teal
            { 192, 192, 192, 255 },     // Name: Silver
            { 128, 128, 128, 255 },     // Name: Grey
            { 255, 0, 0, 255 },         // Name: Red
            { 0, 255, 0, 255 },         // Name: Lime
            { 255, 255, 0, 255 },       // Name: Yellow
            { 0, 0, 255, 255 },         // Name: Blue
            { 255, 0, 255, 255 },       // Name: Fuchsia
            { 0, 255, 255, 255 },       // Name: Aqua
            { 255, 255, 255, 255 },     // Name: White
            { 0, 0, 0, 255 },           // Name: Grey0
            { 0, 0, 95, 255 },          // Name: NavyBlue
            { 0, 0, 135, 255 },         // Name: DarkBlue
            { 0, 0, 175, 255 },         // Name: Blue3
            { 0, 0, 215, 255 },         // Name: Blue3
            { 0, 0, 255, 255 },         // Name: Blue1
            { 0, 95, 0, 255 },          // Name: DarkGreen
            { 0, 95, 95, 255 },         // Name: DeepSkyBlue4
            { 0, 95, 135, 255 },        // Name: DeepSkyBlue4
            { 0, 95, 175, 255 },        // Name: DeepSkyBlue4
            { 0, 95, 215, 255 },        // Name: DodgerBlue3
            { 0, 95, 255, 255 },        // Name: DodgerBlue2
            { 0, 135, 0, 255 },         // Name: Green4
            { 0, 135, 95, 255 },        // Name: SpringGreen4
            { 0, 135, 135, 255 },       // Name: Turquoise4
            { 0, 135, 175, 255 },       // Name: DeepSkyBlue3
            { 0, 135, 215, 255 },       // Name: DeepSkyBlue3
            { 0, 135, 255, 255 },       // Name: DodgerBlue1
            { 0, 175, 0, 255 },         // Name: Green3
            { 0, 175, 95, 255 },        // Name: SpringGreen3
            { 0, 175, 135, 255 },       // Name: DarkCyan
            { 0, 175, 175, 255 },       // Name: LightSeaGreen
            { 0, 175, 215, 255 },       // Name: DeepSkyBlue2
            { 0, 175, 255, 255 },       // Name: DeepSkyBlue1
            { 0, 215, 0, 255 },         // Name: Green3
            { 0, 215, 95, 255 },        // Name: SpringGreen3
            { 0, 215, 135, 255 },       // Name: SpringGreen2
            { 0, 215, 175, 255 },       // Name: Cyan3
            { 0, 215, 215, 255 },       // Name: DarkTurquoise
            { 0, 215, 255, 255 },       // Name: Turquoise2
            { 0, 255, 0, 255 },         // Name: Green1
            { 0, 255, 95, 255 },        // Name: SpringGreen2
            { 0, 255, 135, 255 },       // Name: SpringGreen1
            { 0, 255, 175, 255 },       // Name: MediumSpringGreen
            { 0, 255, 215, 255 },       // Name: Cyan2
            { 0, 255, 255, 255 },       // Name: Cyan1
            { 95, 0, 0, 255 },          // Name: DarkRed
            { 95, 0, 95, 255 },         // Name: DeepPink4
            { 95, 0, 135, 255 },        // Name: Purple4
            { 95, 0, 175, 255 },        // Name: Purple4
            { 95, 0, 215, 255 },        // Name: Purple3
            { 95, 0, 255, 255 },        // Name: BlueViolet
            { 95, 95, 0, 255 },         // Name: Orange4
            { 95, 95, 95, 255 },        // Name: Grey37
            { 95, 95, 135, 255 },       // Name: MediumPurple4
            { 95, 95, 175, 255 },       // Name: SlateBlue3
            { 95, 95, 215, 255 },       // Name: SlateBlue3
            { 95, 95, 255, 255 },       // Name: RoyalBlue1
            { 95, 135, 0, 255 },        // Name: Chartreuse4
            { 95, 135, 95, 255 },       // Name: DarkSeaGreen4
            { 95, 135, 135, 255 },      // Name: PaleTurquoise4
            { 95, 135, 175, 255 },      // Name: SteelBlue
            { 95, 135, 215, 255 },      // Name: SteelBlue3
            { 95, 135, 255, 255 },      // Name: CornflowerBlue
            { 95, 175, 0, 255 },        // Name: Chartreuse3
            { 95, 175, 95, 255 },       // Name: DarkSeaGreen4
            { 95, 175, 135, 255 },      // Name: CadetBlue
            { 95, 175, 175, 255 },      // Name: CadetBlue
            { 95, 175, 215, 255 },      // Name: SkyBlue3
            { 95, 175, 255, 255 },      // Name: SteelBlue1
            { 95, 215, 0, 255 },        // Name: Chartreuse3
            { 95, 215, 95, 255 },       // Name: PaleGreen3
            { 95, 215, 135, 255 },      // Name: SeaGreen3
            { 95, 215, 175, 255 },      // Name: Aquamarine3
            { 95, 215, 215, 255 },      // Name: MediumTurquoise
            { 95, 215, 255, 255 },      // Name: SteelBlue1
            { 95, 255, 0, 255 },        // Name: Chartreuse2
            { 95, 255, 95, 255 },       // Name: SeaGreen2
            { 95, 255, 135, 255 },      // Name: SeaGreen1
            { 95, 255, 175, 255 },      // Name: SeaGreen1
            { 95, 255, 215, 255 },      // Name: Aquamarine1
            { 95, 255, 255, 255 },      // Name: DarkSlateGray2
            { 135, 0, 0, 255 },         // Name: DarkRed
            { 135, 0, 95, 255 },        // Name: DeepPink4
            { 135, 0, 135, 255 },       // Name: DarkMagenta
            { 135, 0, 175, 255 },       // Name: DarkMagenta
            { 135, 0, 215, 255 },       // Name: DarkViolet
            { 135, 0, 255, 255 },       // Name: Purple
            { 135, 95, 0, 255 },        // Name: Orange4
            { 135, 95, 95, 255 },       // Name: LightPink4
            { 135, 95, 135, 255 },      // Name: Plum4
            { 135, 95, 175, 255 },      // Name: MediumPurple3
            { 135, 95, 215, 255 },      // Name: MediumPurple3
            { 135, 95, 255, 255 },      // Name: SlateBlue1
            { 135, 135, 0, 255 },       // Name: Yellow4
            { 135, 135, 95, 255 },      // Name: Wheat4
            { 135, 135, 135, 255 },     // Name: Grey53
            { 135, 135, 175, 255 },     // Name: LightSlateGrey
            { 135, 135, 215, 255 },     // Name: MediumPurple
            { 135, 135, 255, 255 },     // Name: LightSlateBlue
            { 135, 175, 0, 255 },       // Name: Yellow4
            { 135, 175, 95, 255 },      // Name: DarkOliveGreen3
            { 135, 175, 135, 255 },     // Name: DarkSeaGreen
            { 135, 175, 175, 255 },     // Name: LightSkyBlue3
            { 135, 175, 215, 255 },     // Name: LightSkyBlue3
            { 135, 175, 255, 255 },     // Name: SkyBlue2
            { 135, 215, 0, 255 },       // Name: Chartreuse2
            { 135, 215, 95, 255 },      // Name: DarkOliveGreen3
            { 135, 215, 135, 255 },     // Name: PaleGreen3
            { 135, 215, 175, 255 },     // Name: DarkSeaGreen3
            { 135, 215, 215, 255 },     // Name: DarkSlateGray3
            { 135, 215, 255, 255 },     // Name: SkyBlue1
            { 135, 255, 0, 255 },       // Name: Chartreuse1
            { 135, 255, 95, 255 },      // Name: LightGreen
            { 135, 255, 135, 255 },     // Name: LightGreen
            { 135, 255, 175, 255 },     // Name: PaleGreen1
            { 135, 255, 215, 255 },     // Name: Aquamarine1
            { 135, 255, 255, 255 },     // Name: DarkSlateGray1
            { 175, 0, 0, 255 },         // Name: Red3
            { 175, 0, 95, 255 },        // Name: DeepPink4
            { 175, 0, 135, 255 },       // Name: MediumVioletRed
            { 175, 0, 175, 255 },       // Name: Magenta3
            { 175, 0, 215, 255 },       // Name: DarkViolet
            { 175, 0, 255, 255 },       // Name: Purple
            { 175, 95, 0, 255 },        // Name: DarkOrange3
            { 175, 95, 95, 255 },       // Name: IndianRed
            { 175, 95, 135, 255 },      // Name: HotPink3
            { 175, 95, 175, 255 },      // Name: MediumOrchid3
            { 175, 95, 215, 255 },      // Name: MediumOrchid
            { 175, 95, 255, 255 },      // Name: MediumPurple2
            { 175, 135, 0, 255 },       // Name: DarkGoldenrod
            { 175, 135, 95, 255 },      // Name: LightSalmon3
            { 175, 135, 135, 255 },     // Name: RosyBrown
            { 175, 135, 175, 255 },     // Name: Grey63
            { 175, 135, 215, 255 },     // Name: MediumPurple2
            { 175, 135, 255, 255 },     // Name: MediumPurple1
            { 175, 175, 0, 255 },       // Name: Gold3
            { 175, 175, 95, 255 },      // Name: DarkKhaki
            { 175, 175, 135, 255 },     // Name: NavajoWhite3
            { 175, 175, 175, 255 },     // Name: Grey69
            { 175, 175, 215, 255 },     // Name: LightSteelBlue3
            { 175, 175, 255, 255 },     // Name: LightSteelBlue
            { 175, 215, 0, 255 },       // Name: Yellow3
            { 175, 215, 95, 255 },      // Name: DarkOliveGreen3
            { 175, 215, 135, 255 },     // Name: DarkSeaGreen3
            { 175, 215, 175, 255 },     // Name: DarkSeaGreen2
            { 175, 215, 215, 255 },     // Name: LightCyan3
            { 175, 215, 255, 255 },     // Name: LightSkyBlue1
            { 175, 255, 0, 255 },       // Name: GreenYellow
            { 175, 255, 95, 255 },      // Name: DarkOliveGreen2
            { 175, 255, 135, 255 },     // Name: PaleGreen1
            { 175, 255, 175, 255 },     // Name: DarkSeaGreen2
            { 175, 255, 215, 255 },     // Name: DarkSeaGreen1
            { 175, 255, 255, 255 },     // Name: PaleTurquoise1
            { 215, 0, 0, 255 },         // Name: Red3
            { 215, 0, 95, 255 },        // Name: DeepPink3
            { 215, 0, 135, 255 },       // Name: DeepPink3
            { 215, 0, 175, 255 },       // Name: Magenta3
            { 215, 0, 215, 255 },       // Name: Magenta3
            { 215, 0, 255, 255 },       // Name: Magenta2
            { 215, 95, 0, 255 },        // Name: DarkOrange3
            { 215, 95, 95, 255 },       // Name: IndianRed
            { 215, 95, 135, 255 },      // Name: HotPink3
            { 215, 95, 175, 255 },      // Name: HotPink2
            { 215, 95, 215, 255 },      // Name: Orchid
            { 215, 95, 255, 255 },      // Name: MediumOrchid1
            { 215, 135, 0, 255 },       // Name: Orange3
            { 215, 135, 95, 255 },      // Name: LightSalmon3
            { 215, 135, 135, 255 },     // Name: LightPink3
            { 215, 135, 175, 255 },     // Name: Pink3
            { 215, 135, 215, 255 },     // Name: Plum3
            { 215, 135, 255, 255 },     // Name: Violet
            { 215, 175, 0, 255 },       // Name: Gold3
            { 215, 175, 95, 255 },      // Name: LightGoldenrod3
            { 215, 175, 135, 255 },     // Name: Tan
            { 215, 175, 175, 255 },     // Name: MistyRose3
            { 215, 175, 215, 255 },     // Name: Thistle3
            { 215, 175, 255, 255 },     // Name: Plum2
            { 215, 215, 0, 255 },       // Name: Yellow3
            { 215, 215, 95, 255 },      // Name: Khaki3
            { 215, 215, 135, 255 },     // Name: LightGoldenrod2
            { 215, 215, 175, 255 },     // Name: LightYellow3
            { 215, 215, 215, 255 },     // Name: Grey84
            { 215, 215, 255, 255 },     // Name: LightSteelBlue1
            { 215, 255, 0, 255 },       // Name: Yellow2
            { 215, 255, 95, 255 },      // Name: DarkOliveGreen1
            { 215, 255, 135, 255 },     // Name: DarkOliveGreen1
            { 215, 255, 175, 255 },     // Name: DarkSeaGreen1
            { 215, 255, 215, 255 },     // Name: Honeydew2
            { 215, 255, 255, 255 },     // Name: LightCyan1
            { 255, 0, 0, 255 },         // Name: Red1
            { 255, 0, 95, 255 },        // Name: DeepPink2
            { 255, 0, 135, 255 },       // Name: DeepPink1
            { 255, 0, 175, 255 },       // Name: DeepPink1
            { 255, 0, 215, 255 },       // Name: Magenta2
            { 255, 0, 255, 255 },       // Name: Magenta1
            { 255, 95, 0, 255 },        // Name: OrangeRed1
            { 255, 95, 95, 255 },       // Name: IndianRed1
            { 255, 95, 135, 255 },      // Name: IndianRed1
            { 255, 95, 175, 255 },      // Name: HotPink
            { 255, 95, 215, 255 },      // Name: HotPink
            { 255, 95, 255, 255 },      // Name: MediumOrchid1
            { 255, 135, 0, 255 },       // Name: DarkOrange
            { 255, 135, 95, 255 },      // Name: Salmon1
            { 255, 135, 135, 255 },     // Name: LightCoral
            { 255, 135, 175, 255 },     // Name: PaleVioletRed1
            { 255, 135, 215, 255 },     // Name: Orchid2
            { 255, 135, 255, 255 },     // Name: Orchid1
            { 255, 175, 0, 255 },       // Name: Orange1
            { 255, 175, 95, 255 },      // Name: SandyBrown
            { 255, 175, 135, 255 },     // Name: LightSalmon1
            { 255, 175, 175, 255 },     // Name: LightPink1
            { 255, 175, 215, 255 },     // Name: Pink1
            { 255, 175, 255, 255 },     // Name: Plum1
            { 255, 215, 0, 255 },       // Name: Gold1
            { 255, 215, 95, 255 },      // Name: LightGoldenrod2
            { 255, 215, 135, 255 },     // Name: LightGoldenrod2
            { 255, 215, 175, 255 },     // Name: NavajoWhite1
            { 255, 215, 215, 255 },     // Name: MistyRose1
            { 255, 215, 255, 255 },     // Name: Thistle1
            { 255, 255, 0, 255 },       // Name: Yellow1
            { 255, 255, 95, 255 },      // Name: LightGoldenrod1
            { 255, 255, 135, 255 },     // Name: Khaki1
            { 255, 255, 175, 255 },     // Name: Wheat1
            { 255, 255, 215, 255 },     // Name: Cornsilk1
            { 255, 255, 255, 255 },     // Name: Grey100
            { 8, 8, 81, 255 },          // Name: Grey3
            { 8, 18, 182, 255 },        // Name: Grey7
            { 8, 28, 28, 255 },         // Name: Grey11
            { 38, 38, 38, 255 },        // Name: Grey15
            { 48, 48, 48, 255 },        // Name: Grey19
            { 58, 58, 58, 255 },        // Name: Grey23
            { 68, 68, 68, 255 },        // Name: Grey27
            { 78, 78, 78, 255 },        // Name: Grey30
            { 88, 88, 88, 255 },        // Name: Grey35
            { 98, 98, 98, 255 },        // Name: Grey39
            { 108, 108, 108, 255 },     // Name: Grey42
            { 118, 118, 118, 255 },     // Name: Grey46
            { 128, 128, 128, 255 },     // Name: Grey50
            { 138, 138, 138, 255 },     // Name: Grey54
            { 148, 148, 148, 255 },     // Name: Grey58
            { 158, 158, 158, 255 },     // Name: Grey62
            { 168, 168, 168, 255 },     // Name: Grey66
            { 178, 178, 178, 255 },     // Name: Grey70
            { 188, 188, 188, 255 },     // Name: Grey74
            { 198, 198, 198, 255 },     // Name: Grey78
            { 208, 208, 208, 255 },     // Name: Grey82
            { 218, 218, 218, 255 },     // Name: Grey85
            { 228, 228, 228, 255 },     // Name: Grey89
            { 238, 238, 238, 255 }      // Name: Grey93
        };
    };

    struct UEPColourSequence
    {
        UEPColourSequence()
        {
            for (auto& a : attributes)
                a = false;
        }
        UEPTrueColour foregroundColour = { 255, 255, 255, 255 };
        UEPTrueColour backgroundColour = { 0, 0, 0, 0 };
        bool attributes[66]{};
        uint8_t currentFont = 0;
    };
}