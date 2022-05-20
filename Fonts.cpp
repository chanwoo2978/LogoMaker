//
// Created by Chan Lee on 2022-03-19.
//

#include "Fonts.h"
std::map<FontsName, sf::Font> Fonts::fonts;
std::map<FontsName, bool> Fonts::fontList;

bool Fonts::loaded = false;
void Fonts::loadFonts(FontsName fontName)
{
    if(!loaded)
    {
        if(!fonts[fontName].loadFromFile(getFontPath(fontName)))
        {
            exit(1);

        }
        //loaded = true;
    }
}
std::string Fonts::getFontPath(FontsName fontName)
{
    switch(fontName)
    {
        case OPENSANSBOLD:return "Fonts/OpenSans-Bold.ttf";
        case ARIAL:return "Fonts/arial.ttf";
        case WINDSONG:return "Fonts/Windsong.ttf";
        case GABRIOLA:return "Fonts/Gabriola.ttf";
        case INKFREE:return "Fonts/Inkfree.ttf";
        case SEGOESC:return "Fonts/segoesc.ttf";
        case SYLFAEN:return "Fonts/sylfaen.ttf";
    }
}
sf::Font &Fonts::getFont(FontsName fontName)
{
    loadFonts(fontName);
    return fonts[fontName];
}

//bool Fonts::isFontEnabled(FontsName font)
//{
//    return fontList[font];
//}
//void Fonts::setFontEnable(FontsName font, bool set)
//{
//   fontList[font] = set;
//}