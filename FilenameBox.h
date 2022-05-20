//
// Created by Chan Lee on 2022-04-30.
//

#ifndef LOGOMAKER_FILENAMEBOX_H
#define LOGOMAKER_FILENAMEBOX_H
#include <SFML/Graphics.hpp>
#include "Fonts.h"
#include "States.h"

class FilenameBox : public sf::Drawable, public sf::Transformable{
private:
    sf::Text text;
    sf::RectangleShape inputBox;

    void center();
    void initialize();
public:
    FilenameBox();
    FilenameBox(std::string text);
    FilenameBox(std::string text, sf::Vector2f size);
    FilenameBox(std::string text, sf::Vector2f size, sf::Color color);


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


#endif //LOGOMAKER_FILENAMEBOX_H
