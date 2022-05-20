//
// Created by Chan Lee on 2022-03-19.
//

#ifndef INPUTTEXT_LETTER_H
#define INPUTTEXT_LETTER_H
#include <SFML/Graphics.hpp>
#include "Fonts.h"
#include "States.h"

class Letter : public sf::Text {

public:
    Letter();
    Letter(std::string letter);
    Letter(char letter);

};


#endif //INPUTTEXT_LETTER_H
