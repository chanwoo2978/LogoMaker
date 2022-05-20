//
// Created by Chan Lee on 2022-03-30.
//

#include "Menu.h"

Menu::Menu()
{
    setSize(200, 30);

    isClick = false;
    isDrop = false;
}
Menu::Menu(std::string item)
{
    setSize(200, 30);
    this->item.setString(item);;
}

void Menu::setPosition(float x, float y)
{
    this->x = x;
    this->y = y;
    item.setPosition(x, y);
    itemList.setPosition(x, y+item.getGlobalBounds().height);
}
void Menu::setSize(float x, float y)
{
    item.setSize(x, y);
    itemList.setSize(x, y);
}
void Menu::addItem(std::string item)
{
    itemList.addItem(item);

}
void Menu::setString(std::string item)
{
    this->item.setString(item);
}
bool Menu::isClicked()
{
    return isClick;
}

std::string Menu::getString()
{
    isClick = false;
    return label;
}

void Menu::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
    if(isDrop)
    {
        itemList.addEventHandler(window, event);
    }
    if(MouseEvents<Item>::mouseClicked(item, window))
    {
        if(isDrop)
        {
            isDrop = false;
        }
        else
        {
            isDrop = true;
        }
    }
    else if(MouseEvents<ItemList>::mouseClicked(window, event)&&!MouseEvents<ItemList>::hovered(itemList, window))
    {
        label = itemList.getText();
        if(label == "New Project")
        {
            std::cout << "New project click\n";
            States::setMenuEnable(NEW_PROJECT, true);
        }
        else if(label == "Open Project")
        {
            std::cout << "Open Project click\n";
            States::setMenuEnable(OPEN_PROJECT, true);
        }
        else if(label == "Close Project")
        {
            std::cout << "Close Project click\n";
            States::setMenuEnable(CLOSE_PROJECT, true);
        }
        else if(label == "Save Project")
        {
            std::cout << "Save Project click\n";
            States::setMenuEnable(SAVE_PROJECT, true);
        }
        else if(label == "Quit")
        {
            std::cout << "Quit click\n";
            States::setMenuEnable(QUIT_PROJECT, true);
        }
        else if(label == "Redo")
        {
            std::cout << "Redo click\n";
            States::setMenuEnable(REDO_PROJECT, true);
        }
        else if(label == "Export Project")
        {
            std::cout << "Export Project click\n";
            States::setMenuEnable(EXPORT_PROJECT, true);
        }
        isDrop = false;
    }
    setPosition(x, y);
}
void Menu::update()
{
    //if(States::isStateEnabled(CLICK))
    //{
    //    item.setString(itemList.getString());
    //    setPosition(x, y);
    //    label = itemList.getString();
    //}
    if(itemList.click())
    {
        isClick = false;
        isDrop = false;
        label = itemList.getText();
        setPosition(x, y);
    }
}
void Menu::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(item);
    if(isDrop)
    {
        window.draw(itemList);
    }
    //if(States::isStateEnabled(DROPDOWN))
    //{
    //    window.draw(itemList);
    //}
}

sf::FloatRect Menu::getGlobalBounds()
{
    return item.getGlobalBounds();
}
