//
// Created by Chan Lee on 2022-04-20.
//

#include "ColorPicker.h"

ColorPicker::ColorPicker()
{
    colorBox.setFillColor(sf::Color::White);
    setPosition(colorBox.getPosition().x, colorBox.getPosition().y);
    isDrop = false;
    isRGB = false;
}

void ColorPicker::setPosition(float x, float y)
{
    colorBox.setPosition(x, y);
    colorList.setPosition(x, y + colorBox.getGlobalBounds().height);
    rgb.setPosition(x, y + colorBox.getGlobalBounds().height);
}
sf::Color ColorPicker::getColor()
{
    return colorBox.getColor();
}
void ColorPicker::setColor(sf::Color color)
{
    colorBox.setColor(color);
}
sf::FloatRect ColorPicker::getGlobalBounds()
{
    return colorBox.getGlobalBounds();
}

void ColorPicker::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
    sf::Vector2i position = sf::Mouse::getPosition(window);
    if(MouseEvents<ColorBox>::mouseClicked(colorBox, window))
    {
        //if(States::isStateEnabled(COLORLIST))
        //{
        //    States::setStateEnable(COLORLIST, false);
        //}
        //else if(!States::isStateEnabled(COLORLIST))
        //{
        //    States::setStateEnable(COLORLIST, true);
        //}
        if(isDrop)
        {
            isDrop = false;
        }
        else
        {
            isDrop = true;
            if(isRGB)
            {
                isRGB = false;
            }
        }
    }
    else if(MouseEvents<ColorList>::mouseClicked(colorList, window) && isDrop)
    {
        //for(int i=0; i<colorList.getList(); i++)
        //{
        //}
        //std::vector<ColorBox>& vec = colorList.getList();
        //for(int i=0; i<vec.size(); i++)
        //{
        //    States::setStateEnable(COLORLIST, false);
        //}
        std::vector<ColorBox>& vec = colorList.getColorList();
        for(int i = 0; i < vec.size(); i++){
            if(vec.at(i).getGlobalBounds().contains(position.x, position.y))
            {
                rgb.setColor(colorList.getColorByIndex(i));//setColor of rgb by each index
                rgb.setPosition(colorBox.getPosition().x,
                                colorBox.getPosition().y + colorBox.getGlobalBounds().height);
                isDrop = false;
                isRGB = true;
            }
        }
    }
    else if(MouseEvents<ColorRGB>::mouseClicked(rgb, window) && isRGB)
    {
        colorBox.setColor(rgb.getColor(position));
    }
    else if(MouseEvents<ColorBox>::mouseClicked(window, event) &&
            !MouseEvents<ColorBox>::hovered(colorBox, window) &&
            !MouseEvents<ColorRGB>::hovered(rgb, window) &&
            !MouseEvents<ColorList>::hovered(colorList, window))
    {
        //States::setStateEnable(COLORLIST, false);
        isDrop = false;
        isRGB = false;
    }
}
void ColorPicker::update()
{
}
void ColorPicker::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(colorBox);
    if(isDrop)
    {
        window.draw(colorList);
    }
    else if(isRGB)
    {
        window.draw(rgb);
    }
}
