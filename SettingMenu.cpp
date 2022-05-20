//
// Created by Chan Lee on 2022-04-19.
//

#include "SettingMenu.h"
SettingMenu::SettingMenu()
{
    Slider textOpa = Slider("Text Opacity", 255, 255);
    sliderKey[TEXT_OPACITY] = index++;
    sliders.push_back(textOpa);
    Slider shadowOpa = Slider("Shadow Opacity", 255, 127);
    sliderKey[SHADOW_OPACITY] = index++;
    sliders.push_back(shadowOpa);
    Slider backgroundOpa = Slider("Background Opacity", 255, 255);
    sliderKey[BACKGROUND_OPACITY] = index++;
    sliders.push_back(backgroundOpa);

    Slider fontSize = Slider("Font Size", 150, 70);
    sliderKey[FONT_SIZE] = index++;
    sliders.push_back(fontSize);
    Slider skew = Slider("Skew", 100, 55);
    sliderKey[SKEW] = index++;
    sliders.push_back(skew);

    Slider textRotate = Slider("Text Rotate", 360, 0);
    sliderKey[TEXT_ROTATE] = index++;
    sliders.push_back(textRotate);
    Slider shadowRotate = Slider("Shadow Rotate", 360, 0);
    sliderKey[SHADOW_ROTATE] = index++;
    sliders.push_back(shadowRotate);

    Slider xAxis = Slider("Text X-Axis", 900, 401);
    sliderKey[TEXT_X_AXIS] = index++;
    sliders.push_back(xAxis);
    Slider yAxis = Slider("Text Y-Axis", 900, 241);
    sliderKey[TEXT_Y_AXIS] = index++;
    sliders.push_back(yAxis);
    Slider shadowXAxis = Slider("Shadow X-Axis", 900, 401);
    sliderKey[SHADOW_X_AXIS] = index++;
    sliders.push_back(shadowXAxis);
    Slider ShadowYAxis = Slider("Shadow Y-Axis", 900, 340);
    sliderKey[SHADOW_Y_AXIS] = index++;
    sliders.push_back(ShadowYAxis);

}

void SettingMenu::setPosition(float x, float y)
{
    textInput.setPosition({x, y});
    fontMenu.setPosition(x + textInput.getPosition().x + textInput.getGlobalBound().width + 10, y - 1);
    colorMenu.setPosition(x + fontMenu.getPosition().x + fontMenu.getGlobalBounds().width, y - 1);

    sliders.at(0).setPosition(x + textInput.getPosition().x,
                              textInput.getGlobalBound().top + textInput.getGlobalBound().height + yPadding);//text opacity pos
    sliders.at(1).setPosition(sliders.at(0).getPosition().x,
                              sliders.at(0).getPosition().y + sliders.at(0).getGlobalBounds().height + yPadding);//shadow opacity pos
    sliders.at(2).setPosition(sliders.at(1).getPosition().x,
                              sliders.at(1).getPosition().y + sliders.at(1).getGlobalBounds().height + yPadding);//background opacity pos

    sliders.at(3).setPosition(x + sliders.at(0).getPosition().x + sliders.at(0).getGlobalBounds().width + xPadding,
                              sliders.at(0).getPosition().y);//font size pos
    sliders.at(4).setPosition(x + xPadding + sliders.at(3).getPosition().x + sliders.at(3).getGlobalBounds().width,
                              sliders.at(0).getPosition().y);//skew pos

    sliders.at(5).setPosition(sliders.at(1).getPosition().x + sliders.at(1).getGlobalBounds().width + xPadding,
                              sliders.at(1).getPosition().y);//text rotate pos
    sliders.at(6).setPosition(sliders.at(2).getPosition().x + sliders.at(2).getGlobalBounds().width + xPadding,
                              sliders.at(2).getPosition().y);//shadow rotate pos

    sliders.at(7).setPosition(sliders.at(0).getPosition().x,
                              sliders.at(2).getPosition().y + sliders.at(2).getGlobalBounds().height + yPadding);//text x-axis pos
    sliders.at(8).setPosition(sliders.at(0).getPosition().x,
                              sliders.at(7).getPosition().y + sliders.at(8).getGlobalBounds().height + yPadding);//text y-axis pos
    sliders.at(9).setPosition(sliders.at(0).getPosition().x,
                              sliders.at(8).getPosition().y + sliders.at(8).getGlobalBounds().height + yPadding);//shadow x-axis pos
    sliders.at(10).setPosition(sliders.at(0).getPosition().x,
                              sliders.at(9).getPosition().y + sliders.at(9).getGlobalBounds().height + yPadding);//shadow y-axis pos
}
void SettingMenu::setSize(float x, float y)
{
    fontMenu.setSize(x, y);
}
void SettingMenu::setFont(FontsName font)
{
    fontMenu.setFont(font);
}
void SettingMenu::reset()
{
    //for redo menubar and New project menubar
    //set default value of sliders
    colorMenu.setBackgroundColor({50,50,100});
    sliders[0].setLabelValue(255);
    sliders[1].setLabelValue(127);
    sliders[2].setLabelValue(255);
    sliders[3].setLabelValue(70);
    sliders[4].setLabelValue(55);
    sliders[5].setLabelValue(0);
    sliders[6].setLabelValue(0);
    sliders[7].setLabelValue(401);
    sliders[8].setLabelValue(241);
    sliders[9].setLabelValue(401);
    sliders[10].setLabelValue(340);
    fontMenu.setFont(OPENSANSBOLD);
    colorMenu.setTextColor(sf::Color::Blue);
    colorMenu.setOutlineTextColor(sf::Color::Red);
    colorMenu.setBackgroundColor({50,50,100});
}
void SettingMenu::setSlidersValue(Sliders key, int value)
{
    sliderKey[key] = value;
}

sf::Font &SettingMenu::getFont()
{
    return Fonts::getFont(fontMenu.getFont());
}
std::string SettingMenu::getText()
{
    return textInput.getString();
}
sf::Color SettingMenu::getOutlineColor()
{
    return colorMenu.getOutlineTextColor();
}
sf::Color SettingMenu::getTextColor()
{
    return colorMenu.getTextColor();
}
sf::Color SettingMenu::getBackgroundColor()
{
    return colorMenu.getBackgroundColor();
}
int SettingMenu::getSlidersValue(Sliders key)
{
    //map
    int index = sliderKey[key];
    Slider slider = sliders.at(index);
    return slider.getValueLabel();//get value of knob
    //sf::RenderWindow window;
    //int window_width = window.getSize().x;
    //int window_height = window.getSize().y;
}

void SettingMenu::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
    textInput.addEventHandler(window, event);
    fontMenu.addEventHandler(window, event);
    colorMenu.addEventHandler(window, event);
    for(int i = 0; i < sliders.size(); i ++)
    {
        sliders.at(i).addEventHandler(window, event);
    }
}
void SettingMenu::update()
{
    textInput.update();
    fontMenu.update();
    //colorMenu.update();
}
void SettingMenu::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    for(int i = 0; i < sliders.size(); i ++)
    {
        window.draw(sliders.at(i));
    }
    window.draw(textInput);
    window.draw(fontMenu);
    window.draw(colorMenu);
}

Snapshot &SettingMenu::getSnapshot()
{

}
void SettingMenu::applySnapshot(const Snapshot &snapshot)
{

}
