//
// Created by Chan Lee on 2022-04-19.
//

#include "ColorList.h"

ColorList::ColorList()
{
    ColorBox black(sf::Color::Black);
    colorList.push_back(black);
    ColorBox white(sf::Color::White);
    colorList.push_back(white);
    ColorBox red(sf::Color::Red);
    colorList.push_back(red);
    ColorBox green(sf::Color::Green);
    colorList.push_back(green);
    ColorBox blue(sf::Color::Blue);
    colorList.push_back(blue);
    ColorBox yellow(sf::Color::Yellow);
    colorList.push_back(yellow);
    ColorBox magenta(sf::Color::Magenta);
    colorList.push_back(magenta);
    ColorBox cyan(sf::Color::Cyan);
    colorList.push_back(cyan);

    //x-axis:5 padding + 4 width box + 1 outline box, y-axis:3 padding + 2 height box + 1 outline box
    colorBox.setSize({5*padding + 4*red.getGlobalBounds().width + red.getOutlineThickness(),
                      3*padding + 2*red.getGlobalBounds().height + red.getOutlineThickness()});

    colorBox.setFillColor({50,50,80});
}

void ColorList::setPosition(float x, float y)
{
    colorBox.setPosition(x, y);
    for(int i = 0; i < colorList.size(); i++)
    {
        //(box.getOutlineThickness()+i%4):padding between color list (width)
        //0%4+1=1, 1%4+1=2, 2%4+1=3, 3%4+1=4
        //(box.getOutlineThickness()+i/4):padding between color list (height)
        //0/4+1=1, 1/4+1=1, 2/4+1=1, 3/4+1=1
        colorList.at(i).setPosition(x + padding*(box.getOutlineThickness()+i%4) + colorList.at(i).getGlobalBounds().width*(i%4),
                                    y + padding*(box.getOutlineThickness()+i/4) + colorList.at(i).getGlobalBounds().height*(i/4));
    }
}

std::vector<ColorBox> &ColorList::getColorList()
{
    return colorList;
}

sf::FloatRect ColorList::getGlobalBounds()
{
    return colorBox.getGlobalBounds();
}

sf::Color ColorList::getColorByIndex(int index)
{
    return colorList.at(index).getColor();
}

void ColorList::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(colorBox);
    for(int i = 0; i < colorList.size(); i++)
    {
        window.draw(colorList.at(i));
    }
}
