//
// Created by Chan Lee on 2022-03-19.
//

#ifndef INPUTTEXT_MULTITEXT_H
#define INPUTTEXT_MULTITEXT_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include <iterator>
#include "Letter.h"
#include "MouseEvents.h"

class MultiText : public sf::Drawable, public sf::Transformable
                  //public std::iterator<std::bidirectional_iterator_tag, std::list<Letter>>{
{
private:
    //std::list<Letter> multiText;
    std::vector<Letter> multiText;
    Letter letter;

    sf::Vector2f startingPoint;
    void setLetterPosition();

public:
    MultiText();

    float getLastXPos();
    void setPosition(sf::Vector2f startingPoint);
    int getCharacterSize();
    void setCharacterSize(unsigned int sizeValue);

    void keywordsColor();
    void operatorColor();
    void numberColor();

    std::string getString();
    void setString(std::string string);

    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};

#endif //INPUTTEXT_MULTITEXT_H
