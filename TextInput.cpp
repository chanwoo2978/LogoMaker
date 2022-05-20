//
// Created by Chan Lee on 3/22/22.
//

#include "TextInput.h"
TextInput::TextInput()
{
    label.setString("Text Input: ");
    label.setCharacterSize(20);
    this->label.setFont(Fonts::getFont(OPENSANSBOLD));
}

void TextInput::setPosition(sf::Vector2f pos)
{
    label.setPosition({pos.x, pos.y});
    textBox.setPosition({pos.x, label.getPosition().y + label.getGlobalBounds().height + 10});

    multiText.setPosition({textBox.getPosition().x, textBox.getPosition().y+textBox.getOutlineThickness()});
    //cursor.setPosition({pos.x,pos.y});

    cursor.setPosition({multiText.getLastXPos()+5,textBox.getPosition().y+textBox.getOutlineThickness()});

    //cursor.setY(pos.y);
    //cursor.setPosition(multiText.getLastXPos(), cursor.getY());

    //cursor.setPosition(multiText.getLastXPos(), textBox.getPosition().y+textBox.getOutlineThickness());
    //multiText.setPosition({pos.x+textBox.getGlobalBounds().height, textBox.getPosition().y + textBox.getOutlineThickness()/2});
}

void TextInput::enable()
{
    isEnable = true;
    cursor.isEnable();
    States::setStateEnable(HIDDEN, true);
    States::setStateEnable(OUTLINE, true);
}
void TextInput::disable()
{
    isEnable = false;
    cursor.isEnable();
    States::setStateEnable(OUTLINE, false);
}
bool TextInput::checkEnable()
{
    return isEnable;
}
void TextInput::setString(std::string string)
{
    multiText.setString(string);
}

std::string TextInput::getString()
{
    return multiText.getString();
}
sf::FloatRect TextInput::getGlobalBound()
{
    return textBox.getGlobalBounds();
}

void TextInput::addEventHandler(sf::RenderWindow& window, sf::Event event)
{
    //HistoryNode h ={this, getSnapshot()};
    //History::push(h);
    //History::top().component->applySnapshot(History::top().snapshot);
    if(MouseEvents<TextBox>::mouseClicked(textBox, window))
    {
        enable();
        std::cout << "textbox click" << std::endl;
    }
    else if(MouseEvents<TextBox>::mouseClicked(window, event) && !MouseEvents<TextBox>::hovered(textBox, window))
    {
        disable();
        std::cout << "window click" << std::endl;
    }
    if(isEnable)
    {
        multiText.addEventHandler(window, event);
    }
    if(KeyboardShortcuts::isUndo(window, event))
    {
        std::cout << "undo!!" << std::endl;
        //History::pop();

    }
}
void TextInput::update()
{
    if(States::isStateEnabled(OUTLINE))
    {
        textBox.setOutlineThickness(2);
    }
    else
    {
        textBox.setOutlineThickness(1);
    }
    if(isEnable)
    {
        cursor.setPosition({multiText.getLastXPos(), textBox.getPosition().y+textBox.getOutlineThickness()});
        cursor.update();
    }
}
void TextInput::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    window.draw(textBox);
    window.draw(label);
    window.draw(multiText);
    if(isEnable)
    {
        window.draw(cursor);
    }
}

Snapshot &TextInput::getSnapshot()
{
}
void TextInput::applySnapshot(const Snapshot &snapshot)
{
}
