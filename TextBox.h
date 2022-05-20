//
// Created by Chan Lee on 2022-03-19.
//

#ifndef INPUTTEXT_TEXTBOX_H
#define INPUTTEXT_TEXTBOX_H
#include <SFML/Graphics.hpp>
#include "MouseEvents.h"
#include "States.h"

class TextBox : public sf::RectangleShape{
private:
    sf::RectangleShape textBox;
public:
    TextBox();
    TextBox(float width, float height, sf::Color color);

};


#endif //INPUTTEXT_TEXTBOX_H
