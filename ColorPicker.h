//
// Created by Chan Lee on 2022-04-20.
//

#ifndef LOGOMAKER_COLORPICKER_H
#define LOGOMAKER_COLORPICKER_H
#include "ColorList.h"
#include "MouseEvents.h"
#include "GUIComponent.h"
#include "ColorRGB.h"

class ColorPicker : public sf::Drawable, public sf::Transformable{
private:
    ColorList colorList;
    ColorBox colorBox;
    ColorRGB rgb;

    bool isDrop;
    bool isRGB;
public:
    ColorPicker();

    void setPosition(float x, float y);
    sf::Color getColor();
    void setColor(sf::Color color);
    sf::FloatRect getGlobalBounds();

    //from EventHandler
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
    //from the sf::Drawable class
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};


#endif //LOGOMAKER_COLORPICKER_H
