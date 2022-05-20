//
// Created by Chan Lee on 2022-04-20.
//

#include "ColorMenu.h"

ColorMenu::ColorMenu()
{
    this->outlineTextLabel.setFont(Fonts::getFont(OPENSANSBOLD));
    this->textLabel.setFont(Fonts::getFont(OPENSANSBOLD));
    this->backgroundLabel.setFont(Fonts::getFont(OPENSANSBOLD));

    outlineTextLabel.setCharacterSize(20);
    textLabel.setCharacterSize(20);
    backgroundLabel.setCharacterSize(20);

    outlineTextLabel.setString("Outline Color");
    textLabel.setString("Text Color");
    backgroundLabel.setString("Background Color");

    outlineTextColor.setColor(sf::Color::Red);
    textColor.setColor(sf::Color::Blue);
    backgroundColor.setColor({50,50,100});//light violet color

    outlineTextLabel.setFillColor(sf::Color::White);
    textLabel.setFillColor(sf::Color::White);
    backgroundLabel.setFillColor(sf::Color::White);

    isDrop = false;
}

void ColorMenu::setPosition(float x, float y)
{
    padding = 15;

    outlineTextLabel.setPosition(x, y);
    outlineTextColor.setPosition(x,y + outlineTextLabel.getGlobalBounds().height + 15);

    textLabel.setPosition(x + outlineTextLabel.getGlobalBounds().width + padding, y);
    textColor.setPosition(x + outlineTextLabel.getGlobalBounds().width + padding,
                          y + textLabel.getGlobalBounds().height + 15);

    backgroundLabel.setPosition(x + outlineTextLabel.getGlobalBounds().width + textLabel.getGlobalBounds().width + 2*padding, y);
    backgroundColor.setPosition(x + outlineTextLabel.getGlobalBounds().width + textLabel.getGlobalBounds().width + 2*padding,
                                y + textLabel.getGlobalBounds().height + 15);
}
void ColorMenu::setTextColor(sf::Color color)
{
    textColor.setColor(color);
}
sf::Color ColorMenu::getTextColor()
{
    return textColor.getColor();
}
void ColorMenu::setBackgroundColor(sf::Color color)
{
    backgroundColor.setColor(color);
}
sf::Color ColorMenu::getBackgroundColor()
{
    return backgroundColor.getColor();
}
void ColorMenu::setOutlineTextColor(sf::Color color)
{
    outlineTextColor.setColor(color);
}
sf::Color ColorMenu::getOutlineTextColor()
{
    return outlineTextColor.getColor();
}

sf::FloatRect ColorMenu::getGlobalBounds()
{

}

void ColorMenu::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
    textColor.addEventHandler(window, event);
    backgroundColor.addEventHandler(window, event);
    outlineTextColor.addEventHandler(window, event);
}
void ColorMenu::update()
{
}
void ColorMenu::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(textColor);
    window.draw(backgroundColor);
    window.draw(outlineTextColor);
    window.draw(textLabel);
    window.draw(backgroundLabel);
    window.draw(outlineTextLabel);
}

Snapshot &ColorMenu::getSnapshot()
{
}
void ColorMenu::applySnapshot(const Snapshot &snapshot)
{
}
