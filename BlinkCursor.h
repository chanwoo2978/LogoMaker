//
// Created by Chan Lee on 2022-03-22.
//

#ifndef INPUTTEXT_BLINKCURSOR_H
#define INPUTTEXT_BLINKCURSOR_H
#include <SFML/Graphics.hpp>
#include "Fonts.h"
#include "States.h"

class BlinkCursor : public sf::Text{
private:
    sf::RectangleShape cursor;
    sf::Clock clock;

    bool enable;
public:
    BlinkCursor();

    void isEnable();
    void isDisable();

    float getX() const;
    float getY() const;
    void setPosition(sf::Vector2f position);

    void update();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};


#endif //INPUTTEXT_BLINKCURSOR_H
