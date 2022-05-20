//
// Created by Chan Lee on 2022-03-19.
//

#include "Letter.h"

Letter::Letter()
: Letter(' ')
{

}

Letter::Letter(std::string letter)
: Letter(letter[0])
{

}

Letter::Letter(char letter)
{
    setString(letter);
    setFont(Fonts::getFont(FontsName::OPENSANSBOLD));
    //setCharacterSize(20);
}
