//
// Created by Chan Lee on 2022-04-19.
//

#ifndef LOGOMAKER_COLORBOX_H
#define LOGOMAKER_COLORBOX_H
#include <SFML/Graphics.hpp>

class ColorBox : public sf::RectangleShape{
public:
    ColorBox();
    ColorBox(sf::Color color);

    void setColor(sf::Color color);
    sf::Color getColor() const;
};


#endif //LOGOMAKER_COLORBOX_H
