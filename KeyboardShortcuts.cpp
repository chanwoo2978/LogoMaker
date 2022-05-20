//
// Created by Chan Lee on 2022-03-30.
//

#include "KeyboardShortcuts.h"
bool KeyboardShortcuts::isUndo(sf::RenderWindow& window, sf::Event event)
{
    if(event.key.control && event.key.code == sf::Keyboard::Z)
    {
        return true;
    }
    else
    {
        return false;
    }
}