//
// Created by Chan Lee on 2022-03-30.
//

#include "MenuBar.h"

MenuBar::MenuBar()
{
    Menu temp;
    temp.setString("File");
    temp.addItem("New Project");
    temp.addItem("Open Project");
    temp.addItem("Close Project");
    temp.addItem("Save Project");
    temp.addItem("Quit");
    menuBar.push_back(temp);
    Menu temp2;
    temp2.setString("Edit");
    temp2.addItem("Redo");
    menuBar.push_back(temp2);
    Menu temp3;
    temp3.setString("Render");
    temp3.addItem("Export Project");
    menuBar.push_back(temp3);
    setPosition(1,1);
}

void MenuBar::addItem(std::string item)
{
    Menu menu;
    menu.addItem(item);
    menuBar.push_back(menu);
}
void MenuBar::setString(std::string item)
{
    Menu menu;
    menu.setString(item);
}
void MenuBar::setPosition(float x, float y)
{
    int counter = 0;
    for(std::vector<Menu>::iterator iter = menuBar.begin(); iter < menuBar.end(); ++iter)
    {
        iter->setPosition((x + iter->getGlobalBounds().width) * counter, y);
        counter++;
    }
}
void MenuBar::setSize(float x, float y)
{
    for(std::vector<Menu>::iterator iter = menuBar.begin(); iter < menuBar.end(); ++iter)
    {
        iter->setSize(x, y);
    }
}

void MenuBar::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
    for(std::vector<Menu>::iterator iter = menuBar.begin(); iter < menuBar.end(); ++iter)
    {
        iter->addEventHandler(window, event);
    }

}
void MenuBar::update()
{

}
void MenuBar::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    for(Menu m : menuBar)
    {
        window.draw(m);
    }
}

Snapshot &MenuBar::getSnapshot()
{
}
void MenuBar::applySnapshot(const Snapshot &snapshot)
{
}
sf::FloatRect MenuBar::getGlobalBounds()
{
    for(int i = 0; i < menuBar.size(); i++)
    {
        sf::FloatRect rect;
        rect.left = menuBar.at(i).getPosition().x;
        rect.width = menuBar.at(i).getGlobalBounds().width;
        rect.top = menuBar.at(i).getPosition().y;
        rect.height = menuBar.at(i).getGlobalBounds().height;

        return rect;
    }

}