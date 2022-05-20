//
// Created by Chan Lee on 2022-04-20.
//

#ifndef LOGOMAKER_COLORMENU_H
#define LOGOMAKER_COLORMENU_H
#include "ColorPicker.h"
#include "GUIComponent.h"
#include "Fonts.h"
class ColorMenu : public GUIComponent{
private:
    ColorPicker textColor;
    ColorPicker backgroundColor;
    ColorPicker outlineTextColor;
    sf::Text textLabel;
    sf::Text backgroundLabel;
    sf::Text outlineTextLabel;

    int padding;
    bool isDrop;
public:
    ColorMenu();

    void setPosition(float x, float y);
    void setTextColor(sf::Color color);
    sf::Color getTextColor();
    void setBackgroundColor(sf::Color color);
    sf::Color getBackgroundColor();
    void setOutlineTextColor(sf::Color color);
    sf::Color getOutlineTextColor();

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


#endif //LOGOMAKER_COLORMENU_H
