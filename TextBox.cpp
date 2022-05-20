//
// Created by Chan Lee on 2022-03-19.
//

#include "TextBox.h"
TextBox::TextBox()
: TextBox(400, 30, sf::Color::White)
{

}

TextBox::TextBox(float width, float height, sf::Color color)
: sf::RectangleShape({width, height})
{
    setSize({width, height});
    setOutlineColor(sf::Color::White);
    setFillColor({55,55,55,255});
    setOutlineThickness(1);
}