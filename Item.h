//
// Created by Chan Lee on 2022-03-30.
//

#ifndef DROPDOWNMENU_ITEM_H
#define DROPDOWNMENU_ITEM_H
#include <SFML/Graphics.hpp>
#include "MouseEvents.h"
#include "Fonts.h"
#include "GUIComponent.h"
#include "InputBox.h"

class Item : public sf::Drawable, public sf::Transformable{
private:
    //TextBox textBox;
    sf::Text text;
    sf::RectangleShape inputBox;
    //InputBox box;

    void center();
    void initialize();
public:
    Item();
    Item(std::string text);
    Item(std::string text, sf::Vector2f size);

    void setSize(float x, float y);
    void setPosition(float x, float y);
    void setString(std::string label);
    std::string getString() const;
    void setOutlineThickness(float thickness);
    float getOutlineThickness();
    void setFillColor(sf::Color color);

    //from the sf::Drawable class
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    //from EventHandler
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();

    sf::FloatRect getGlobalBounds();
    bool operator==(const Item& other);
};


#endif //DROPDOWNMENU_ITEM_H
