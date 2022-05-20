//
// Created by Chan Lee on 2022-03-30.
//

#include "ItemList.h"

ItemList::ItemList()
{
}
void ItemList::setPosition(float x, float y)
{
    int counter = 0;
    for(int i = 0; i < itemList.size(); i++)
    {
        itemList.at(i).setPosition(x, y + (item.getOutlineThickness() + itemList.at(i).getGlobalBounds().height) * counter);
        ++counter;
    }
}
void ItemList::setSize(float x, float y)
{
    item.setSize(x, y);
    for(int i = 0; i < itemList.size(); i++)
    {
        itemList.at(i).setSize(x, y);
    }
}
void ItemList::setOutlineThickness(float thickness)
{
}
void ItemList::addItem(std::string list)
{
    Item temp(list);
    itemList.push_back(temp);
}
bool ItemList::click()
{
    return isClick;
}

std::string ItemList::getText()
{
    return label;
}
sf::FloatRect ItemList::getGlobalBounds()
{
    sf::FloatRect rect;
    rect.left = itemList.at(0).getPosition().x;
    rect.width = itemList.at(0).getGlobalBounds().width;
    int counter = itemList.size();
    rect.top = itemList.at(0).getPosition().y;
    rect.height *= counter;
    return rect;
}

void ItemList::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
    for(int i = 0; i < itemList.size(); i++)
    {
        if(MouseEvents<Item>::hovered(itemList.at(i), window))
        {
            itemList.at(i).setFillColor({50,50,80});
        }
        else
        {
            itemList.at(i).setFillColor({55,55,55,255});
        }
        if(MouseEvents<Item>::mouseClicked(itemList.at(i), window))
        {
            States::setStateEnable(DROPDOWN, false);
            States::setStateEnable(CLICK, true);
            isClick = true;
            label = itemList.at(i).getString();
            //std::cout << "item click" << itemList.at(i).getString();
        }
    }
    setPosition(getPosition().x, getPosition().y);
}
void ItemList::update()
{
}
void ItemList::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    if(!itemList.empty())
    {
        for(int i = 0; i < itemList.size(); i++)
        {
            window.draw(itemList.at(i));
        }
    }
}
//std::list<Item>::const_iterator ItemList::begin() const
//{
//    return itemList.begin();
//}
//
//std::list<Item>::const_iterator ItemList::end() const
//{
//    return itemList.end();
//}

