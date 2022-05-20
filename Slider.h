//
// Created by Chan Lee on 2022-04-23.
//

#ifndef LOGOMAKER_SLIDER_H
#define LOGOMAKER_SLIDER_H
#include "GUIComponent.h"
#include "Fonts.h"
#include "MouseEvents.h"
class Slider : public GUIComponent{
private:
    sf::Text label;
    sf::Text valLabel; //value of slider label
    sf::RectangleShape slider;
    sf::CircleShape knob;

    int knobPos;
    int padding = 10;
public:
    Slider();
    Slider(std::string label);
    Slider(std::string label, float size, float defaultValue = 0);

    void setPosition(float x, float y);
    void initialize();
    void setLabel(std::string label);
    void setLabelValue(float value);

    std::string getLabel();
    float getValueLabel();
    sf::Vector2f getPosition();
    sf::FloatRect getGlobalBounds();

    //from the sf::Drawable class
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    //from EventHandler
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();

    //from SnapshotInterface
    virtual Snapshot& getSnapshot();
    virtual void applySnapshot(const Snapshot& snapshot);
};


#endif //LOGOMAKER_SLIDER_H
