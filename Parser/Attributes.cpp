#include "Attributes.hpp"
#include "Sequences.hpp"

void UEP::Attributes::checkAttribute(const uint8_t& num, ParserInfo& info, UEPColourSequence& currentColour)
{
    switch (num)
    {
    case Sequences::Attributes::AllReset:
        for (auto& a : currentColour.attributes)
            a = false;
        break;
    case Sequences::Attributes::Bold:
        currentColour.attributes[Sequences::Attributes::Bold] = true;
        break;
    case Sequences::Attributes::Dim:
        currentColour.attributes[Sequences::Attributes::Dim] = true;
        break;
    case Sequences::Attributes::Italic:
        currentColour.attributes[Sequences::Attributes::Italic] = true;
        break;
    case Sequences::Attributes::Underlined:
        currentColour.attributes[Sequences::Attributes::Underlined] = true;
        break;
    case Sequences::Attributes::Blink:
        currentColour.attributes[Sequences::Attributes::Blink] = true;
        break;
    case Sequences::Attributes::RapidBlink:
        currentColour.attributes[Sequences::Attributes::RapidBlink] = true;
        break;
    case Sequences::Attributes::Invert:
        currentColour.attributes[Sequences::Attributes::Invert] = true;
        break;
    case Sequences::Attributes::Hidden:
        currentColour.attributes[Sequences::Attributes::Hidden] = true;
        break;
    case Sequences::Attributes::CrossedOut:
        currentColour.attributes[Sequences::Attributes::CrossedOut] = true;
        break;
    case Sequences::Attributes::PrimaryFont:
        currentColour.attributes[Sequences::Attributes::PrimaryFont] = true;
        break;
    case Sequences::Attributes::Fraktur:
        currentColour.attributes[Sequences::Attributes::Fraktur] = true;
        break;
    case Sequences::Attributes::Framed:
        currentColour.attributes[Sequences::Attributes::Framed] = true;
        break;
    case Sequences::Attributes::Encircled:
        currentColour.attributes[Sequences::Attributes::Encircled] = true;
        break;
    case Sequences::Attributes::Overlined:
        currentColour.attributes[Sequences::Attributes::Overlined] = true;
        break;
    case Sequences::Attributes::ResetFramedAndEncircled:
        currentColour.attributes[Sequences::Attributes::Framed] = false;
        currentColour.attributes[Sequences::Attributes::Encircled] = false;
        break;
    case Sequences::Attributes::ResetOverlined:
        currentColour.attributes[Sequences::Attributes::Overlined] = false;
        break;
    case Sequences::Attributes::IdeogramUnderline:
        currentColour.attributes[Sequences::Attributes::IdeogramUnderline] = true;
        break;
    case Sequences::Attributes::IdeogramDoubleUnderline:
        currentColour.attributes[Sequences::Attributes::IdeogramDoubleUnderline] = true;
        break;
    case Sequences::Attributes::IdeogramOverline:
        currentColour.attributes[Sequences::Attributes::IdeogramOverline] = true;
        break;
    case Sequences::Attributes::IdeogramDoubleOverline:
        currentColour.attributes[Sequences::Attributes::IdeogramDoubleOverline] = true;
        break;
    case Sequences::Attributes::IdeogramStressMarking:
        currentColour.attributes[Sequences::Attributes::IdeogramStressMarking] = true;
        break;
    case Sequences::Attributes::ResetIdeograms:
        currentColour.attributes[Sequences::Attributes::IdeogramStressMarking] = false;
        currentColour.attributes[Sequences::Attributes::IdeogramDoubleOverline] = false;
        currentColour.attributes[Sequences::Attributes::IdeogramOverline] = false;
        currentColour.attributes[Sequences::Attributes::IdeogramUnderline] = false;
        currentColour.attributes[Sequences::Attributes::IdeogramDoubleUnderline] = false;
        break;
    case Sequences::Attributes::ResetBold:
        currentColour.attributes[Sequences::Attributes::Bold] = false;
        break;
    case Sequences::Attributes::ResetDim:
        currentColour.attributes[Sequences::Attributes::Dim] = false;
        break;
    case Sequences::Attributes::ResetItalic:
        currentColour.attributes[Sequences::Attributes::Italic] = false;
        currentColour.attributes[Sequences::Attributes::Fraktur] = false;
        break;
    case Sequences::Attributes::ResetUnderlined:
        currentColour.attributes[Sequences::Attributes::Underlined] = false;
        break;
    case Sequences::Attributes::ResetBlink:
        currentColour.attributes[Sequences::Attributes::Blink] = false;
        break;
    case Sequences::Attributes::ResetReverse:
        currentColour.attributes[Sequences::Attributes::Invert] = false;
        break;
    case Sequences::Attributes::ResetHidden:
        currentColour.attributes[Sequences::Attributes::Hidden] = false;
        break;
    case Sequences::Attributes::ResetCrossedOut:
        currentColour.attributes[Sequences::Attributes::CrossedOut] = false;
        break;
    case Sequences::Colours::Foreground::DefaultColour:
        currentColour.foregroundColour = info.white;
        break;
    case Sequences::Colours::Foreground::Black:
        currentColour.foregroundColour = info.black;
        break;
    case Sequences::Colours::Foreground::Red:
        currentColour.foregroundColour = info.red;
        break;
    case Sequences::Colours::Foreground::Green:
        currentColour.foregroundColour = info.green;
        break;
    case Sequences::Colours::Foreground::Yellow:
        currentColour.foregroundColour = info.yellow;
        break;
    case Sequences::Colours::Foreground::Blue:
        currentColour.foregroundColour = info.blue;
        break;
    case Sequences::Colours::Foreground::Magenta:
        currentColour.foregroundColour = info.magenta;
        break;
    case Sequences::Colours::Foreground::Cyan:
        currentColour.foregroundColour = info.cyan;
        break;
    case Sequences::Colours::Foreground::LightGrey:
        currentColour.foregroundColour = info.lightgrey;
        break;
    case Sequences::Colours::Foreground::DarkGrey:
        currentColour.foregroundColour = info.grey;
        break;
    case Sequences::Colours::Foreground::LightRed:
        currentColour.foregroundColour = info.lightred;
        break;
    case Sequences::Colours::Foreground::LightGreen:
        currentColour.foregroundColour = info.lightgreen;
        break;
    case Sequences::Colours::Foreground::LightYellow:
        currentColour.foregroundColour = info.lightyellow;
        break;
    case Sequences::Colours::Foreground::LightBlue:
        currentColour.foregroundColour = info.lightblue;
        break;
    case Sequences::Colours::Foreground::LightMagenta:
        currentColour.foregroundColour = info.lightmagenta;
        break;
    case Sequences::Colours::Foreground::LightCyan:
        currentColour.foregroundColour = info.lightcyan;
        break;
    case Sequences::Colours::Foreground::White:
        currentColour.foregroundColour = info.white;
        break;
    case Sequences::Colours::Background::DefaultColour:
        currentColour.backgroundColour = info.black;
        break;
    case Sequences::Colours::Background::Black:
        currentColour.backgroundColour = info.black;
        break;
    case Sequences::Colours::Background::Red:
        currentColour.backgroundColour = info.red;
        break;
    case Sequences::Colours::Background::Green:
        currentColour.backgroundColour = info.green;
        break;
    case Sequences::Colours::Background::Yellow:
        currentColour.backgroundColour = info.yellow;
        break;
    case Sequences::Colours::Background::Blue:
        currentColour.backgroundColour = info.blue;
        break;
    case Sequences::Colours::Background::Magenta:
        currentColour.backgroundColour = info.magenta;
        break;
    case Sequences::Colours::Background::Cyan:
        currentColour.backgroundColour = info.cyan;
        break;
    case Sequences::Colours::Background::LightGrey:
        currentColour.backgroundColour = info.lightgrey;
        break;
    case Sequences::Colours::Background::DarkGrey:
        currentColour.backgroundColour = info.grey;
        break;
    case Sequences::Colours::Background::LightRed:
        currentColour.backgroundColour = info.lightred;
        break;
    case Sequences::Colours::Background::LightGreen:
        currentColour.backgroundColour = info.lightgreen;
        break;
    case Sequences::Colours::Background::LightYellow:
        currentColour.backgroundColour = info.lightyellow;
        break;
    case Sequences::Colours::Background::LightBlue:
        currentColour.backgroundColour = info.lightblue;
        break;
    case Sequences::Colours::Background::LightMagenta:
        currentColour.backgroundColour = info.lightmagenta;
        break;
    case Sequences::Colours::Background::LightCyan:
        currentColour.backgroundColour = info.cyan;
        break;
    case Sequences::Colours::Background::White:
        currentColour.backgroundColour = info.white;
        break;
    case Sequences::Attributes::AlternativeFont1:
        currentColour.currentFont = 1;
        break;
    case Sequences::Attributes::AlternativeFont2:
        currentColour.currentFont = 2;
        break;
    case Sequences::Attributes::AlternativeFont3:
        currentColour.currentFont = 3;
        break;
    case Sequences::Attributes::AlternativeFont4:
        currentColour.currentFont = 4;
        break;
    case Sequences::Attributes::AlternativeFont5:
        currentColour.currentFont = 5;
        break;
    case Sequences::Attributes::AlternativeFont6:
        currentColour.currentFont = 6;
        break;
    case Sequences::Attributes::AlternativeFont7:
        currentColour.currentFont = 7;
        break;
    case Sequences::Attributes::AlternativeFont8:
        currentColour.currentFont = 8;
        break;
    case Sequences::Attributes::AlternativeFont9:
        currentColour.currentFont = 9;
        break;
    case Sequences::Colours::Foreground::DefaultUnderlinedColour:
        currentColour.underlinedColour = info.white;
        break;
    case Sequences::Attributes::ProportionalSpacing:
        currentColour.attributes[Sequences::Attributes::ProportionalSpacing] = true;
        break;
    case Sequences::Attributes::DisableProportionalSpacing:
        currentColour.attributes[Sequences::Attributes::ProportionalSpacing] = false;
        break;
    default:
        break;
    }
}