//
// Created by Chan Lee on 2022-03-19.
//

#ifndef INPUTTEXT_MOUSEEVENTS_CPP
#define INPUTTEXT_MOUSEEVENTS_CPP
#include "MouseEvents.h"
template <class T>
int MouseEvents<T>::clicks;

template <class T>
sf::Clock MouseEvents<T>::clock;

template <class T>
bool MouseEvents<T>::mouseClicked(T& object, sf::RenderWindow& window)
{
    //if(hovered(object, window) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
    if(hovered(object, window) && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {
        if(clock.getElapsedTime().asMilliseconds() <= 500)
        {
            clicks++;
            clock.restart();
        }
        else
        {
            clicks = 1;
            clock.restart();
        }
        return true;
    }
    else
    {
        return false;
    }
}

template <class T>
bool MouseEvents<T>::mouseClicked(sf::RenderWindow& window, sf::Event event)
{
    //if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
    if((event.type == event.MouseButtonPressed) && (event.mouseButton.button == sf::Mouse::Button::Left))
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class T>
bool MouseEvents<T>::mouseDoubleClicked()
{
    if(clicks == 2)
    {
        clicks = 0;
        return true;
    }
    else
    {
        return false;
    }
}

template <class T>
bool MouseEvents<T>::mouseTripleClicked()
{
    return (clicks == 3);
}

template <class T>
bool MouseEvents<T>::draggedOver(T& object, sf::RenderWindow& window, sf::Event event)
{
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && hovered(object, window))
    {
        if(event.type != event.MouseButtonReleased && event.type == event.MouseMoved)
        {
            return true;
        }
    }
    return false;
}

template <class T>
bool MouseEvents<T>::hovered(T& object, sf::RenderWindow& window)
{
    //sf::Vector2i pos = sf::Mouse::getPosition(window);
    sf::Vector2f pos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
    if(object.getGlobalBounds().contains(pos.x, pos.y))
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class T>
void MouseEvents<T>::countClicks(sf::Event event)
{
    while(clock.getElapsedTime().asSeconds() <= 1)
    {
        if((event.type == event.MouseButtonPressed) &&
        (event.mouseButton.button == sf::Mouse::Button::Left))
        {
            clock.restart();
            ++clicks;
        }
    }
}

#endif