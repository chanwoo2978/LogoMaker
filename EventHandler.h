//
// Created by Chan Lee on 2022-03-17.
//

#ifndef INPUTTEXT_EVENTHANDLER_H
#define INPUTTEXT_EVENTHANDLER_H
#include <SFML/Graphics.hpp>

class EventHandler{
public:
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event) = 0;
    virtual void update() = 0;
};
#endif //INPUTTEXT_EVENTHANDLER_H
