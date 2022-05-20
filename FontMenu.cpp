//
// Created by Chan Lee on 2022-04-19.
//

#include "FontMenu.h"

FontMenu::FontMenu()
{
    label.setString("Font Settings");
    label.setFont(Fonts::getFont(OPENSANSBOLD));
    label.setCharacterSize(20);

    fontDrop.addItem("Arial");
    fontDrop.addItem("Windsong");
    fontDrop.addItem("Gabriola");
    fontDrop.addItem("Inkfree");
    fontDrop.addItem("OpenSans");
    fontDrop.addItem("Segoesc");
    fontDrop.addItem("Sylfaen");

}

void FontMenu::setPosition(float x, float y)
{
    label.setPosition(x, y);
    fontDrop.setPosition(x, y + label.getGlobalBounds().height + 10);
}
void FontMenu::setSize(float x, float y)
{
    fontDrop.setSize(x, y);
}
void FontMenu::setFont(FontsName font)
{
    switch(font)
    {
        case OPENSANSBOLD:
            fontDrop.setString("OpenSans");
            break;
        case ARIAL:
            fontDrop.setString("Arial");
            break;
        case WINDSONG:
            fontDrop.setString("Windsong");
            break;
        case GABRIOLA:
            fontDrop.setString("Gabriola");
            break;
        case INKFREE:
            fontDrop.setString("Inkfree");
            break;
        case SEGOESC:
            fontDrop.setString("Segoesc");
            break;
        case SYLFAEN:
            fontDrop.setString("Sylfaen");
            break;
    }
}

FontsName FontMenu::getFont()
{
    std::string font = fontDrop.getString();
    if(font == "OpenSans")
    {
        return OPENSANSBOLD;
    }
    if(font == "Arial")
    {
        return ARIAL;
    }
    else if(font == "Windsong")
    {
        return WINDSONG;
    }
    else if(font == "Gabriola")
    {
        return GABRIOLA;
    }
    else if(font == "Inkfree")
    {
        return INKFREE;
    }
    else if(font == "Segoesc")
    {
        return SEGOESC;
    }
    else if(font == "Sylfaen")
    {
        return SYLFAEN;
    }
}

void FontMenu::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(label);
    window.draw(fontDrop);
}
void FontMenu::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
    fontDrop.addEventHandler(window, event);
}
void FontMenu::update()
{
    fontDrop.update();
}

Snapshot &FontMenu::getSnapshot()
{
}
void FontMenu::applySnapshot(const Snapshot &snapshot)
{
}

sf::Vector2f FontMenu::getPosition()
{
    return label.getPosition();
}
sf::FloatRect FontMenu::getGlobalBounds()
{
    sf::FloatRect rect;
    rect.left = label.getPosition().x;
    rect.top = label.getPosition().y;
    rect.width = fontDrop.getPosition().x + fontDrop.getGlobalBounds().width;
    rect.height = fontDrop.getPosition().y + fontDrop.getGlobalBounds().height;
    return rect;
}
