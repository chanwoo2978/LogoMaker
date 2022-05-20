//
// Created by Chan Lee on 3/24/22.
//

#include "History.h"
std::stack<Snapshot> History::stack;

void History::pushHistory(const Snapshot& snapshot)
{
    stack.push(snapshot);
}

Snapshot History::topHistory()
{
    return stack.top();
}

void History::popHistory()
{
    stack.pop();
}

void History::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
}
