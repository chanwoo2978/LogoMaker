//
// Created by Chan Lee on 2022-04-19.
//

#ifndef LOGOMAKER_COLORLIST_H
#define LOGOMAKER_COLORLIST_H
#include "ColorBox.h"

class ColorList : public sf::Drawable, public sf::Transformable{
private:
    int padding = 7;
    sf::RectangleShape colorBox;
    std::vector<ColorBox> colorList;
    ColorBox box;
public:
    ColorList();
    void setPosition(float x, float y);
    std::vector<ColorBox>& getColorList();
    sf::FloatRect getGlobalBounds();
    sf::Color getColorByIndex(int index);

    //from the sf::Drawable class
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};


#endif //LOGOMAKER_COLORLIST_H
