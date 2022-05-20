//
// Created by Chan Lee on 2022-03-30.
//

#ifndef DROPDOWNMENU_ITEMLIST_H
#define DROPDOWNMENU_ITEMLIST_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include "MouseEvents.h"
#include "Item.h"
#include "GUIComponent.h"
#include "InputBox.h"

class ItemList : public sf::Drawable, public sf::Transformable
        //public std::iterator<std::bidirectional_iterator_tag, std::list<Item>>{
{
private:
    //std::list<Item> itemList;
    std::vector<Item> itemList;
    std::string label;
    Item item;

    bool isClick;
public:
    ItemList();

    int getSize();
    void addItem(std::string list);
    void setOutlineThickness(float thickness);
    void setPosition(float x, float y);
    void setSize(float x, float y);
    bool click();

    std::string getText();
    std::list<Item>::const_iterator begin() const;
    std::list<Item>::const_iterator end() const;

    //from the sf::Drawable class
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    //from EventHandler
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
    sf::FloatRect getGlobalBounds();

};


#endif //DROPDOWNMENU_ITEMLIST_H
