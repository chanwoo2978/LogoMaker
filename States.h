//
// Created by Chan Lee on 2022-03-19.
//

#ifndef INPUTTEXT_STATES_H
#define INPUTTEXT_STATES_H
#include <map>
#include <iostream>
#include <SFML/Graphics.hpp>

enum ObjectState{
    HIDDEN,
    OUTLINE,
    HIGHLIGHT,
    DROPDOWN,
    CLICK,
    COLORLIST,
    ///This should always be the last state
    LASTSTATE
};

enum Colors{
    BLACK,
    WHITE,
    RED,
    GREEN,
    BLUE,
    YELLOW,
    MAGENTA,
    CYAN,

    LASTCOLOR
};

enum Sliders{
    TEXT_OPACITY,
    SHADOW_OPACITY,
    BACKGROUND_OPACITY,
    FONT_SIZE,
    SKEW,
    TEXT_ROTATE,
    SHADOW_ROTATE,
    TEXT_X_AXIS,
    TEXT_Y_AXIS,
    SHADOW_X_AXIS,
    SHADOW_Y_AXIS,

    LASTSLIDER
};

enum Menubars{
    NEW_PROJECT,
    OPEN_PROJECT,
    CLOSE_PROJECT,
    SAVE_PROJECT,
    QUIT_PROJECT,
    REDO_PROJECT,
    EXPORT_PROJECT,

    LASTMENU
};


class States{
private:
    static std::map<ObjectState, bool> states;
    static std::map<Menubars, bool> menus;
public:
    States();

    static bool isStateEnabled(ObjectState state);
    static void setStateEnable(ObjectState state, bool set);

    static bool isMenuEnabled(Menubars menu);
    static void setMenuEnable(Menubars menu, bool set);

};


#endif //INPUTTEXT_STATES_H
