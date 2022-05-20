//
// Created by Chan Lee on 2022-04-19.
//

#include "LogoMaker.h"

LogoMaker::LogoMaker()
{
    background.setSize({1200, 550});
    setPosition(40, 1);
    closeProj = false;
}

void LogoMaker::setPosition(float x, float y)
{
    menuBar.setPosition(1, y);
    background.setPosition(1, menuBar.getPosition().y + menuBar.getGlobalBounds().height);
    settingMenu.setPosition(x, background.getPosition().y + background.getGlobalBounds().height);
}

void LogoMaker::setFillColor(sf::Color color)
{

}
void LogoMaker::setTextMenu()
{
    textColor = settingMenu.getTextColor();
    textOutlineColor = settingMenu.getOutlineColor();
    textColor.a = settingMenu.getSlidersValue(TEXT_OPACITY);
    text.setFillColor(textColor);
    text.setOutlineColor(textOutlineColor);
    text.setOutlineThickness(2);
    text.setString(settingMenu.getText());
    text.setFont(settingMenu.getFont());
    text.setPosition(settingMenu.getSlidersValue(TEXT_X_AXIS),
                     settingMenu.getSlidersValue(TEXT_Y_AXIS));
    text.setCharacterSize(settingMenu.getSlidersValue(FONT_SIZE));
    text.setRotation(settingMenu.getSlidersValue(TEXT_ROTATE));
}
void LogoMaker::setBackgroundMenu()
{
    backgroundColor = settingMenu.getBackgroundColor();
    backgroundColor.a = settingMenu.getSlidersValue(BACKGROUND_OPACITY);
    background.setFillColor(backgroundColor);
}
void LogoMaker::setShadowMenu()
{
    //sf::FloatRect tb = text.getGlobalBounds();
    //shadow.setPosition(tb.left + settingMenu.getSlidersValue(SHADOW_X_AXIS),
    //                   tb.top + text.getCharacterSize()*1.8 + settingMenu.getSlidersValue(SHADOW_Y_AXIS));
    shadow.setPosition(settingMenu.getSlidersValue(SHADOW_X_AXIS) - settingMenu.getSlidersValue(TEXT_X_AXIS),
                       settingMenu.getSlidersValue(SHADOW_Y_AXIS) - settingMenu.getSlidersValue(TEXT_Y_AXIS));
    //std::cout << background.getPosition().x;
    //shadow.setScale(shadow.getScale().x, -1);
    shadow.setScale(shadow.getScale().x, -1*(double)settingMenu.getSlidersValue(SKEW)/150);
    shadowColor = sf::Color::White;
    shadowColor.a = settingMenu.getSlidersValue(SHADOW_OPACITY);
    shadow.setFillColor(shadowColor);
    shadow.setString(settingMenu.getText());
    shadow.setFont(settingMenu.getFont());
    shadow.setCharacterSize(text.getCharacterSize());
    shadow.setRotation(settingMenu.getSlidersValue(SHADOW_ROTATE));
}

sf::FloatRect LogoMaker::getGlobalBounds()
{

}

void LogoMaker::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
    menuBar.addEventHandler(window, event);
    settingMenu.addEventHandler(window, event);
    if(States::isMenuEnabled(NEW_PROJECT))
    {
        settingMenu.reset();
        States::setMenuEnable(NEW_PROJECT, false);
        update();
    }
    else if(States::isMenuEnabled(OPEN_PROJECT))
    {
        ///need implementation of filetree in here
        closeProj = false;
        States::setMenuEnable(OPEN_PROJECT, false);
    }
    else if(States::isMenuEnabled(CLOSE_PROJECT))
    {
        closeProj = true;
        States::setMenuEnable(CLOSE_PROJECT, false);
    }
    else if(States::isMenuEnabled(SAVE_PROJECT))
    {
        ///save as png image, but dont close program
        States::setMenuEnable(SAVE_PROJECT, false);
    }
    else if(States::isMenuEnabled(QUIT_PROJECT))
    {
        window.close();
    }
    else if(States::isMenuEnabled(REDO_PROJECT))
    {
        settingMenu.reset();
        States::setMenuEnable(REDO_PROJECT, false);

    }
    else if(States::isMenuEnabled(EXPORT_PROJECT))
    {
        ///https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Texture.php
        ///https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Image.php#ab2fa337c956f85f93377dcb52153a45a
        filenameWindow.run();
        std::string filename = filenameWindow.getLabel();
        filename = "Logos/" + filename + ".png";

        texture.create((int)background.getSize().x, window.getSize().y);
        texture.update(window);
        source = texture.copyToImage();
        //sf::IntRect intRect;
        //intRect.left = background.getPosition().x;
        //intRect.top = background.getPosition().y + menuBar.getGlobalBounds().height;
        //intRect.width = background.getGlobalBounds().width;
        //intRect.height = background.getGlobalBounds().height - menuBar.getGlobalBounds().height;
        image.create(background.getGlobalBounds().width, background.getGlobalBounds().height, sf::Color::Transparent);
        image.copy(source, destX, destY,
                   sf::IntRect((int)background.getPosition().x,//left
                               (int)background.getPosition().y + menuBar.getGlobalBounds().height,//top
                               (int)background.getGlobalBounds().width,//width
                               (int)background.getGlobalBounds().height - menuBar.getGlobalBounds().height));//height
        //This function performs a slow operation that downloads the texture's pixels from the graphics card and copies them to a new image

        image.saveToFile(filename);
        States::setMenuEnable(EXPORT_PROJECT, false);
        window.close();
    }

}
void LogoMaker::update()
{
    menuBar.update();
    settingMenu.update();
    setTextMenu();
    setBackgroundMenu();
    setShadowMenu();
}

void LogoMaker::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    if(!closeProj)
    {
        window.draw(background);
        states.transform = text.getTransform();
        window.draw(shadow, states);//draw shadow first to set shadow behind text
        window.draw(text);
        window.draw(settingMenu);
    }
    window.draw(menuBar);
}

Snapshot &LogoMaker::getSnapshot()
{
}
void LogoMaker::applySnapshot(const Snapshot &snapshot)
{
}
