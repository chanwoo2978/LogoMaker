//
// Created by Chan Lee on 2022-03-30.
//

#ifndef DROPDOWNMENU_INPUTBOX_H
#define DROPDOWNMENU_INPUTBOX_H
#include <SFML/Graphics.hpp>
#include "Fonts.h"
#include "States.h"
class InputBox : public sf::Drawable, public sf::Transformable{
private:
    sf::Text text;
    sf::RectangleShape inputBox;

    void center();
    void initialize();
public:
    InputBox();
    InputBox(std::string text);
    InputBox(std::string text, sf::Vector2f size);
    InputBox(std::string text, sf::Vector2f size, sf::Color color);


    void setSize(float x, float y);
    void setPosition(float x, float y);
    void setString(std::string label);
    std::string getString() const;
    void setOutlineThickness(float thickness);
    void setFillColor(sf::Color color);
    float getOutLineThickness(float thickness);

    //from the sf::Drawable class
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    sf::FloatRect getGlobalBounds();
};


#endif //DROPDOWNMENU_INPUTBOX_H
