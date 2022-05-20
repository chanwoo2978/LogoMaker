//
// Created by Chan Lee on 2022-03-30.
//

#ifndef MENUBAR_MENU_H
#define MENUBAR_MENU_H
#include "ItemList.h"

class Menu : public sf::Drawable, public sf::Transformable {
private:
    float x;
    float y;
    Item item;
    ItemList itemList;
    std::string label;

    bool isDrop;
    bool isClick;
public:
    Menu();
    Menu(std::string item);

    void setSize(float x, float y);
    void setPosition(float x, float y);
    void addItem(std::string item);
    void setString(std::string item);
    bool isClicked();
    std::string getString();
    std::string getClicked();

    //from the sf::Drawable class
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    //from EventHandler
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();

    sf::FloatRect getGlobalBounds();
};


#endif //MENUBAR_MENU_H
