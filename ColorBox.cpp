//
// Created by Chan Lee on 2022-04-19.
//

#include "ColorBox.h"

ColorBox::ColorBox()
:ColorBox(sf::Color::Black)
{
}
ColorBox::ColorBox(sf::Color color)
{
    setFillColor(color);
    setOutlineColor(sf::Color::White);
    setOutlineThickness(1);
    setSize({30,30});
}
void ColorBox::setColor(sf::Color color)
{
    setFillColor(color);
    setOutlineColor(sf::Color::White);
}
sf::Color ColorBox::getColor() const
{
    return getFillColor();
}
