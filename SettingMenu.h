//
// Created by Chan Lee on 2022-04-19.
//

#ifndef LOGOMAKER_SETTINGMENU_H
#define LOGOMAKER_SETTINGMENU_H
#include "TextInput.h"
#include "FontMenu.h"
#include "GUIComponent.h"
#include "ColorMenu.h"
#include "Slider.h"
#include <fstream>
#include "FilenameWindow.h"
class SettingMenu : public GUIComponent{
private:
    TextInput textInput;
    FontMenu fontMenu;
    ColorMenu colorMenu;
    FilenameWindow filenameWindow;

    ///https://www.youtube.com/watch?v=7mwgA9XFIEQ&ab_channel=TechWithTim
    std::vector<Slider> sliders;
    std::map<Sliders, int> sliderKey;//use key"Sliders(enum)" to access value (int)

    //sf::Window window;
    int xPadding = 10;
    int yPadding = 30;
    int index = 0;
public:
    SettingMenu();

    void setPosition(float x, float y);
    void setSize(float x, float y);
    void setFont(FontsName font);
    void setSlidersValue(Sliders key, int value);

    void reset();
    //fonts
    sf::Font& getFont();
    std::string getText();
    //colors
    sf::Color getOutlineColor();
    sf::Color getTextColor();
    sf::Color getBackgroundColor();
    //sliders
    int getSlidersValue(Sliders key);
    //from the sf::Drawable class
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    //from EventHandler
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();

    //from SnapshotInterface
    virtual Snapshot& getSnapshot();
    virtual void applySnapshot(const Snapshot& snapshot);
};


#endif //LOGOMAKER_SETTINGMENU_H
