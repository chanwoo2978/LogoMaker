//
// Created by Chan Lee on 2022-03-30.
//

#include "InputBox.h"
InputBox::InputBox() : InputBox("OpenSans", {200, 30}, {55,55,55,255})
{
}
InputBox::InputBox(std::string text) : InputBox(text, {200, 30}, {55,55,55,255})
{
}
InputBox::InputBox(std::string text, sf::Vector2f size) : InputBox(text, size, {55,55,55,255})
{
}
InputBox::InputBox(std::string text, sf::Vector2f size, sf::Color color)
{
    this->text.setString(text);
    inputBox.setSize(size);
    inputBox.setFillColor(color);
    inputBox.setOutlineThickness(1);
    this->text.setFont(Fonts::getFont(OPENSANSBOLD));
    this->text.setCharacterSize(20);
    //initialize();
}

void InputBox::center()
{
    //sf::FloatRect bBounds = inputBox.getGlobalBounds();
    //sf::FloatRect tBounds = text.getGlobalBounds();
    //text.setPosition(bBounds.width/2 - tBounds.width/2,
    //                 bBounds.top +bBounds.height/2 - tBounds.height);
    //text.setPosition(inputBox.getGlobalBounds().left+inputBox.getGlobalBounds().width/2-text.getGlobalBounds().width/2,
    //                 inputBox.getGlobalBounds().top+inputBox.getGlobalBounds().height/2-text.getGlobalBounds().height/1.2);

}

void InputBox::initialize()
{
    //text.setFont(Fonts::getFont(OPENSANSBOLD));
    //center();
}

void InputBox::setSize(float x, float y)
{
    inputBox.setSize({x, y});
    text.setCharacterSize(y/2);
}

void InputBox::setPosition(float x, float y)
{
    inputBox.setPosition(x, y);
    //x is inputBox.getGlobalBounds().left
    text.setPosition(x + inputBox.getGlobalBounds().width/2 - text.getGlobalBounds().width/2,
                     y + inputBox.getGlobalBounds().height/2 - text.getGlobalBounds().height/1.2);

    //center();
}

void InputBox::setString(std::string label)
{
    text.setString(label);
    setPosition(getPosition().x, getPosition().y);
}

std::string InputBox::getString() const
{
    return text.getString();
}

void InputBox::setOutlineThickness(float thickness)
{
    inputBox.setOutlineThickness(thickness);
}

void InputBox::setFillColor(sf::Color color)
{
    inputBox.setFillColor(color);
}

float InputBox::getOutLineThickness(float thickness)
{
    return inputBox.getOutlineThickness();
}

void InputBox::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(inputBox);
    window.draw(text);
}

sf::FloatRect InputBox::getGlobalBounds()
{
    return inputBox.getGlobalBounds();
}
