//
// Created by Chan Lee on 2022-04-19.
//

#ifndef LOGOMAKER_FONTMENU_H
#define LOGOMAKER_FONTMENU_H
#include "GUIComponent.h"
#include "DropdownMenu.h"

class FontMenu : public GUIComponent{
private:
    sf::Text label;
    DropdownMenu fontDrop;

public:
    FontMenu();

    void setPosition(float x, float y);
    void setSize(float x, float y);
    void setFont(FontsName font);
    FontsName getFont();

    //from the sf::Drawable class
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    //from EventHandler
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();

    //from SnapshotInterface
    virtual Snapshot& getSnapshot();
    virtual void applySnapshot(const Snapshot& snapshot);

    sf::Vector2f getPosition();
    sf::FloatRect getGlobalBounds();
};


#endif //LOGOMAKER_FONTMENU_H
