//
// Created by Chan Lee on 2022-03-19.
//

#ifndef INPUTTEXT_GUICOMPONENT_H
#define INPUTTEXT_GUICOMPONENT_H
#include <SFML/Graphics.hpp>
#include "EventHandler.h"
#include "States.h"
#include "SnapshotInterface.h"
#include "HistoryNode.h"

class GUIComponent: public sf::Drawable, public sf::Transformable, public SnapshotInterface,
        public EventHandler, public States{
public:
    //from the sf::Drawable class
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const = 0;

    //from EventHandler
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event) = 0;
    virtual void update() = 0;

    //from SnapshotInterface
    virtual Snapshot& getSnapshot() = 0;
    virtual void applySnapshot(const Snapshot& snapshot) = 0;

};
#endif //INPUTTEXT_GUICOMPONENT_H
