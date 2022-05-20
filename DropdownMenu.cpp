//
// Created by Chan Lee on 2022-03-30.
//

#include "DropdownMenu.h"

DropdownMenu::DropdownMenu()
{
    box.setString("OpenSans");
    setSize(200, 30);
}
DropdownMenu::DropdownMenu(std::string item)
{
    box.setString(item);
    this->box.setString(item);
}

void DropdownMenu::setPosition(float x, float y)
{
    this->x = x;
    this->y = y;
    box.setPosition(x, y);
    itemList.setPosition(x, y+box.getGlobalBounds().height);
}
void DropdownMenu::setSize(float x, float y)
{
    box.setSize(x, y);
    itemList.setSize(x, y);
}
void DropdownMenu::setString(std::string item)
{
    this->box.setString(item);
}
void DropdownMenu::addItem(std::string item)
{
    //box.setString(item);//default: 1st
    itemList.addItem(item);
}

std::string DropdownMenu::getString()
{
    return box.getString();
}
sf::FloatRect DropdownMenu::getGlobalBounds()
{
    return box.getGlobalBounds();
}

void DropdownMenu::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
    if(States::isStateEnabled(DROPDOWN))
    {
        itemList.addEventHandler(window, event);
    }
    if(MouseEvents<InputBox>::mouseClicked(box, window))
    {
        //std::cout << "Click Box" << std::endl;
        if(States::isStateEnabled(DROPDOWN))
        {
            States::setStateEnable(DROPDOWN, false);
        }
        else
        {
            States::setStateEnable(DROPDOWN, true);
        }
    }
    else if(MouseEvents<ItemList>::mouseClicked(window, event) &&
            !MouseEvents<ItemList>::hovered(itemList, window))
    {
        States::setStateEnable(DROPDOWN, false);
    }

    setPosition(x, y);
}
void DropdownMenu::update()
{
    if(States::isStateEnabled(CLICK))
    {
        box.setString(itemList.getText());
        setPosition(x, y);
        States::setStateEnable(CLICK, false);
    }
    setPosition(x, y);
}
void DropdownMenu::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(box);
    if(States::isStateEnabled(DROPDOWN))
    {
        window.draw(itemList);
    }
}

Snapshot &DropdownMenu::getSnapshot()
{
}
void DropdownMenu::applySnapshot(const Snapshot &snapshot)
{
}

