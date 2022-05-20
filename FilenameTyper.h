//
// Created by Chan Lee on 2022-04-30.
//

#ifndef LOGOMAKER_FILENAMETYPER_H
#define LOGOMAKER_FILENAMETYPER_H
#include "GUIComponent.h"
#include <SFML/Graphics.hpp>
#include "MultiText.h"
#include "MouseEvents.h"
#include "HistoryNode.h"
#include "BlinkCursor.h"
#include "TextBox.h"

class FilenameTyper : public GUIComponent{
private:
    TextBox textBox;
    MultiText multiText;
    BlinkCursor cursor;

    sf::Text label;
    bool isEnable;
public:
    FilenameTyper();

    void enable();
    void disable();
    bool checkEnable();

    void setPosition(sf::Vector2f pos);
    void setString(std::string string);
    void setFont(FontsName font);
    void setSize(float x, float y);
    void setLength(float len);

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


#endif //LOGOMAKER_FILENAMETYPER_H
