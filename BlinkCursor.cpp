//
// Created by Chan Lee on 2022-03-22.
//

#include "BlinkCursor.h"

BlinkCursor::BlinkCursor()
{
    isDisable();
    sf::Vector2f vec(4, 25);
    cursor.setSize(vec);
    cursor.setOutlineThickness(0.1);
    clock.restart();
}

void BlinkCursor::isEnable()
{
    enable = true;
}

void BlinkCursor::isDisable()
{
    enable = false;
}
void BlinkCursor::setPosition(sf::Vector2f position)
{
    cursor.setPosition({position.x,position.y});
}

float BlinkCursor::getX() const
{
    return cursor.getGlobalBounds().left;
}

float BlinkCursor::getY() const
{
    return cursor.getGlobalBounds().top;
}

void BlinkCursor::update()
{
    if(enable)
    {
        if(clock.getElapsedTime() >= sf::milliseconds(450))
        {
            clock.restart();
            if(States::isStateEnabled(HIDDEN))
            {
                cursor.setFillColor(sf::Color::Transparent);
                cursor.setOutlineColor(sf::Color::Transparent);
                States::setStateEnable(HIDDEN, false);
            }
            else
            {
                cursor.setFillColor(sf::Color::White);
                States::setStateEnable(HIDDEN, true);
            }
        }

    }
}

void BlinkCursor::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    if(enable)
    {
        window.draw(cursor);
    }
}