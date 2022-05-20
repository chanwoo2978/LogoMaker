//
// Created by Chan Lee on 3/24/22.
//

#ifndef INPUTTEXTPROJECT_HISTORY_H
#define INPUTTEXTPROJECT_HISTORY_H
#include <map>
#include <stack>
#include "GUIComponent.h"

class History {
private:
    static std::stack<Snapshot> stack;

public:
    static void pushHistory(const Snapshot& snapshot);
    static Snapshot topHistory();
    //static Snapshot& topHistory();
    static void popHistory();

    static void addEventHandler(sf::RenderWindow& window, sf::Event event);
};


#endif //INPUTTEXTPROJECT_HISTORY_H
