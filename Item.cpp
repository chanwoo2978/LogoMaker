//
// Created by Chan Lee on 2022-03-30.
//

#include "Item.h"

Item::Item() : Item("item", {200, 30})
{
}

Item::Item(std::string text) : Item(text, {200, 30})
{
}

Item::Item(std::string text, sf::Vector2f size)
{
    inputBox.setSize(size);
    inputBox.setFillColor({55,55,55,255});
    inputBox.setOutlineThickness(1);
    this->text.setString(text);
    this->text.setFont(Fonts::getFont(OPENSANSBOLD));
    this->text.setCharacterSize(size.y/2);
    initialize();
}

void Item::center()
{
    //sf::FloatRect bBounds = inputBox.getGlobalBounds();
    //sf::FloatRect tBounds = text.getGlobalBounds();
    //text.setPosition(bBounds.width/2 - tBounds.width/2,
    //                 bBounds.top +bBounds.height/2 - tBounds.height);
    text.setPosition(inputBox.getGlobalBounds().left+inputBox.getGlobalBounds().width/2-text.getGlobalBounds().width/2,
                     inputBox.getGlobalBounds().top+inputBox.getGlobalBounds().height/2-text.getGlobalBounds().height/1.2);
}
void Item::initialize()
{
    this->text.setPosition(inputBox.getPosition().x + inputBox.getGlobalBounds().width/2 - this->text.getGlobalBounds().width/2,
                           inputBox.getPosition().y + inputBox.getGlobalBounds().height/2 - this->text.getGlobalBounds().height/1.2);
}

void Item::setSize(float x, float y)
{
    inputBox.setSize({x, y});
    text.setCharacterSize(y/2);
}

void Item::setPosition(float x, float y)
{
    inputBox.setPosition(x, y);
    text.setPosition(x + inputBox.getGlobalBounds().width/2 - text.getGlobalBounds().width/2,
                     y + inputBox.getGlobalBounds().height/2 - text.getGlobalBounds().height/1.2);
}

void Item::setString(std::string label)
{
    text.setString(label);
}

std::string Item::getString() const
{
    return text.getString();
}

void Item::setOutlineThickness(float thickness)
{
    inputBox.setOutlineThickness(thickness);
}

void Item::setFillColor(sf::Color color)
{
    inputBox.setFillColor(color);
}

float Item::getOutlineThickness()
{
    return inputBox.getOutlineThickness();
}

void Item::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
}

void Item::update()
{
}

void Item::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(inputBox);
    window.draw(text);
}

sf::FloatRect Item::getGlobalBounds()
{
    return inputBox.getGlobalBounds();
}

bool Item::operator==(const Item& other)
{
    return getString() == other.getString();
}