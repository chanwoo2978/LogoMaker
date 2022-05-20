//
// Created by Chan Lee on 2022-03-19.
//

#ifndef INPUTTEXT_FONTS_H
#define INPUTTEXT_FONTS_H
#include <SFML/Graphics.hpp>
#include <map>
#include <iostream>

enum FontsName{
    OPENSANSBOLD,
    ARIAL,
    WINDSONG,
    GABRIOLA,
    INKFREE,
    SEGOESC,
    SYLFAEN,

    LASTFONT
};

class Fonts {
private:
    static std::map<FontsName, sf::Font> fonts;
    static std::map<FontsName, bool> fontList;

    static void loadFonts(FontsName fontName);
    static std::string getFontPath(FontsName fontName);
    static bool loaded;
public:
    static sf::Font& getFont(FontsName fontName);
    static bool isFontEnabled(FontsName font);
    static void setFontEnable(FontsName font, bool set);

};


#endif //INPUTTEXT_FONTS_H
