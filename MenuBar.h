//
// Created by Chan Lee on 2022-03-30.
//

#ifndef MENUBAR_MENUBAR_H
#define MENUBAR_MENUBAR_H
#include "GUIComponent.h"
#include "Menu.h"
#include "DropdownMenu.h"
class MenuBar : public GUIComponent{
private:
    std::vector<Menu> menuBar;

public:
    MenuBar();

    void addItem(std::string item);
    void setPosition(float x, float y);
    void setSize(float x, float y);
    void setString(std::string item);

    //from the sf::Drawable class
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    //from EventHandler
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();

    //from SnapshotInterface
    virtual Snapshot& getSnapshot();
    virtual void applySnapshot(const Snapshot& snapshot);

    sf::FloatRect getGlobalBounds();
};


#endif //MENUBAR_MENUBAR_H
