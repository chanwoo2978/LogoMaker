//
// Created by Chan Lee on 2022-03-19.
//

#include "States.h"
std::map<ObjectState, bool> States::states;
std::map<Menubars, bool> States::menus;

States::States()
{
    for(int i=0; i<LASTSTATE; i++)
    {
        states[ObjectState(i)] = false;
    }
}

bool States::isStateEnabled(ObjectState state)
{
    return states[state];
}


void States::setStateEnable(ObjectState state, bool set)
{
    states[state] = set;
}

bool States::isMenuEnabled(Menubars menu)
{
    return menus[menu];
}

void States::setMenuEnable(Menubars menu, bool set)
{
    menus[menu] = set;
}

//bool States::checkState(ObjectState state)
//{
//    return objectStates[state];
//}
//void States::enableState(ObjectState state)
//{
//    objectStates[state] = true;
//}
//void States::disableState(ObjectState state)
//{
//    objectStates[state] = false;
//}