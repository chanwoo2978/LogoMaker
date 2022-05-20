//
// Created by Chan Lee on 2022-03-19.
//

#include "MultiText.h"
MultiText::MultiText()
{
    setPosition({10.f,0.f});
    setCharacterSize(20);

}
void MultiText::setLetterPosition()
{
    //letter.setPosition((multiText.back().getGlobalBounds().left + multiText.back().getGlobalBounds().width),
    //                   multiText.back().getPosition().y);

    if(!multiText.empty())
    {
        letter.setPosition(multiText.back().getGlobalBounds().left + multiText.back().getGlobalBounds().width,
                           multiText.back().getPosition().y);
    }
    else
    {
        letter.setPosition(getLastXPos(),startingPoint.y);
    }
}

float MultiText::getLastXPos()
{
    if(!multiText.empty())
    {
        return multiText.back().getGlobalBounds().left + multiText.back().getGlobalBounds().width;
    }
    else
    {
        return startingPoint.x;
    }
}

void MultiText::setPosition(sf::Vector2f starting_point)
{
    startingPoint = starting_point;
    letter.setPosition(startingPoint);
    //for(Letter l : multiText)
    //{
    //    l.setPosition(l.getPosition().x + l.getGlobalBounds().width + l.getLetterSpacing(), startingPoint.y);
    //}
}

int MultiText::getCharacterSize()
{

}

void MultiText::setCharacterSize(unsigned int sizeValue)
{
    letter.setCharacterSize(sizeValue);
    for(Letter l : multiText)
    {
        letter.setCharacterSize(sizeValue);
    }
}
std::string MultiText::getString()
{
    //std::string temp = "";
    //for(Letter l : multiText)
    //{
    //    temp += letter.getString();
    //}
    //return temp;

    std::string temp = "";
    for(int i = 0; i < multiText.size(); i++)
    {
        temp += multiText.at(i).getString();
    }
    return temp;
}
void MultiText::setString(std::string string)
{
    letter.setString(string);
}

void MultiText::addEventHandler(sf::RenderWindow& window, sf::Event event)
{

    if(event.type == sf::Event::TextEntered)
    {
        if(event.text.unicode == 8)
        {
            if(!multiText.empty())
            {
                multiText.pop_back();
            }
            setLetterPosition();
        }
        else if(event.text.unicode >= 32 && event.text.unicode < 127)
        {
            letter.setString(static_cast<char>(event.text.unicode));
            numberColor();
            operatorColor();
            keywordsColor();
            multiText.push_back(letter);
            setLetterPosition();
            std::cout << getString();
        }
    }

}
void MultiText::keywordsColor()
{
    if(letter.getString() == "int" || letter.getString() == "Int" || letter.getString() == "double" || letter.getString() == "Double" || letter.getString() == "float" || letter.getString() == "Float"
       || letter.getString() == "char" || letter.getString() == "Char" || letter.getString() == "bool" || letter.getString() == "Bool" || letter.getString() == "void" || letter.getString() == "Void")
    {
        for(Letter l : multiText)
        {
            l.setFillColor(sf::Color::Cyan);
        }
    }
}

void MultiText::operatorColor()
{

    if(letter.getString() == "+" || letter.getString() == "-" || letter.getString() == "(" || letter.getString() == ")" || letter.getString() == "<" || letter.getString() == ">"
       || letter.getString() == "=" || letter.getString() == "/" || letter.getString() == "*" || letter.getString() == "!" || letter.getString() == "%" || letter.getString() == "^")
    {
        letter.setFillColor(sf::Color::Blue);
    }
}

void MultiText::numberColor()
{
    if(letter.getString() == "1" || letter.getString() == "2" || letter.getString() == "3" || letter.getString() == "4" || letter.getString() == "5" || letter.getString() == "6"
       || letter.getString() == "7" || letter.getString() == "8" || letter.getString() == "9" || letter.getString() == "0")
    {
        letter.setFillColor(sf::Color::Red);
    }
    else
        letter.setFillColor(sf::Color::White);

}
void MultiText::update()
{

}

void MultiText::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    for(Letter l : multiText)
    {
        window.draw(l);
    }
}
