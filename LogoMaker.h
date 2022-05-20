//
// Created by Chan Lee on 2022-04-19.
//

#ifndef LOGOMAKER_LOGOMAKER_H
#define LOGOMAKER_LOGOMAKER_H
#include "GUIComponent.h"
#include "MenuBar.h"
#include "SettingMenu.h"
#include "Fonts.h"
#include "TextInput.h"
#include "FilenameWindow.h"

class LogoMaker : public GUIComponent{
private:
    sf::Text text;
    sf::Text shadow;
    sf::RectangleShape background;
    sf::Color textColor;
    sf::Color textOutlineColor;
    sf::Color shadowColor;
    sf::Color backgroundColor;

    sf::Texture texture;
    sf::Image source, image;

    //TextInput textInput;
    //Letter letter;
    MenuBar menuBar;
    SettingMenu settingMenu;
    FilenameWindow filenameWindow;

    unsigned int destX = 10;
    unsigned int destY = 10;
    bool closeProj;
public:
    LogoMaker();

    void setPosition(float x, float y);
    void setFillColor(sf::Color color);
    void setTextMenu();
    void setBackgroundMenu();
    void setShadowMenu();

    sf::FloatRect getGlobalBounds();//in case mouse handler is used

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();

    virtual Snapshot& getSnapshot();
    virtual void applySnapshot(const Snapshot& snapshot);
};


#endif //LOGOMAKER_LOGOMAKER_H
