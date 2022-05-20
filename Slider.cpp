//
// Created by Chan Lee on 2022-04-23.
//

#include "Slider.h"

Slider::Slider() : Slider("slider", 500)
{
}
Slider::Slider(std::string label) : Slider(label, 500)
{
}
Slider::Slider(std::string label, float size, float defaultValue)
{
    knobPos = defaultValue;
    this->label.setFont(Fonts::getFont(OPENSANSBOLD));
    this->label.setCharacterSize(15);
    this->label.setString(label+": ");
    valLabel.setFont(Fonts::getFont(OPENSANSBOLD));
    valLabel.setCharacterSize(15);
    valLabel.setFillColor(sf::Color::White);
    valLabel.setString(std::to_string(knobPos));
    slider.setSize({size, 2});
    slider.setFillColor(sf::Color::White);
    knob.setRadius(8);
    knob.setFillColor(sf::Color::White);
    initialize();
}

void Slider::setPosition(float x, float y)
{
    label.setPosition(x, y);
    initialize();
}
void Slider::initialize()
{
    slider.setPosition(label.getPosition().x + label.getGlobalBounds().width + padding,
                       label.getPosition().y + label.getCharacterSize()/2);
    knob.setPosition(slider.getPosition().x + knobPos - knob.getRadius(),
                     slider.getPosition().y + slider.getGlobalBounds().height/2 - knob.getRadius());//set middle of slider (-knob.getRadius())
    valLabel.setPosition(slider.getPosition().x + slider.getGlobalBounds().width + padding + knob.getRadius(),
                       label.getPosition().y);

}
void Slider::setLabel(std::string label)
{
    this->label.setString(label + ": ");
    initialize();
}
void Slider::setLabelValue(float value)
{
    knobPos = value;
    valLabel.setString(std::to_string(knobPos));
    initialize();
}

std::string Slider::getLabel()
{
    std::string temp = label.getString();
    return temp;
}
float Slider::getValueLabel()
{
    return knobPos;
}

sf::Vector2f Slider::getPosition()
{
    return label.getPosition();
}

sf::FloatRect Slider::getGlobalBounds()
{
    sf::FloatRect rect;
    rect.left = label.getPosition().x;
    rect.width = label.getGlobalBounds().width + slider.getGlobalBounds().width + valLabel.getGlobalBounds().width + 45;//45 between 2 sliders x-axis
    rect.top = label.getPosition().y;
    rect.height = label.getGlobalBounds().height;
    return rect;
}

void Slider::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
    if(MouseEvents<sf::CircleShape>::draggedOver(knob, window, event))
    {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        this->knobPos = mousePos.x - slider.getGlobalBounds().left;
        if(knobPos >= slider.getSize().x)
        {
            knobPos = slider.getSize().x;//til the end of right side of slider
        }
        else if(knobPos <= 0)
        {
            knobPos = 0;//til the end of left side of slider
        }
        this->valLabel.setString(std::to_string(knobPos));
        initialize();//knob follows the sliders
    }
}
void Slider::update()
{
}
void Slider::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(label);
    window.draw(slider);
    window.draw(knob);
    window.draw(valLabel);
}

Snapshot &Slider::getSnapshot()
{
}
void Slider::applySnapshot(const Snapshot &snapshot)
{
}
