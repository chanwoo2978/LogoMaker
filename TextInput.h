//
// Created by Chan Lee on 3/22/22.
//

#ifndef INPUTTEXTPROJECT_TEXTINPUT_H
#define INPUTTEXTPROJECT_TEXTINPUT_H
#include <SFML/Graphics.hpp>
#include "GUIComponent.h"
#include "TextBox.h"
#include "MultiText.h"
#include "MouseEvents.h"
#include "HistoryNode.h"
#include "BlinkCursor.h"
#include "KeyboardShortcuts.h"

class TextInput : public GUIComponent{
private:
    TextBox textBox;
    MultiText multiText;
    BlinkCursor cursor;
    Letter letter;

    sf::Text label;
    bool isEnable;
public:
    TextInput();

    void enable();
    void disable();
    bool checkEnable();

    void setPosition(sf::Vector2f pos);
    void setString(std::string string);
    void setFont(FontsName font);

    std::string getString();
    sf::FloatRect getGlobalBound();

    //from the sf::Drawable class
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    //from EventHandler
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();

    //from SnapshotInterface
    virtual Snapshot& getSnapshot();
    virtual void applySnapshot(const Snapshot& snapshot);
};


#endif //INPUTTEXTPROJECT_TEXTINPUT_H
