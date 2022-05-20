//
// Created by Chan Lee on 2022-03-30.
//

#ifndef DROPDOWNMENU_DROPDOWNMENU_H
#define DROPDOWNMENU_DROPDOWNMENU_H
#include "GUIComponent.h"
#include "ItemList.h"
#include "InputBox.h"
#include "History.h"

class DropdownMenu : public GUIComponent{
private:
    float x;
    float y;
    InputBox box;
    //Item item;
    ItemList itemList;
    Snapshot snapShot;

public:
    DropdownMenu();
    DropdownMenu(std::string item);

    void setSize(float x, float y);
    void setPosition(float x, float y);
    void addItem(std::string item);
    void setString(std::string item);

    std::string getString();
    sf::FloatRect getGlobalBounds();

    //from the sf::Drawable class
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    //from EventHandler
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();

    //from SnapshotInterface
    virtual Snapshot& getSnapshot();
    virtual void applySnapshot(const Snapshot& snapshot);
};


#endif //DROPDOWNMENU_DROPDOWNMENU_H
