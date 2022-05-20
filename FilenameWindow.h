//
// Created by Chan Lee on 2022-04-30.
//

#ifndef LOGOMAKER_FILENAMEWINDOW_H
#define LOGOMAKER_FILENAMEWINDOW_H
#include "FilenameTyper.h"
#include "FilenameBox.h"

class FilenameWindow {
private:
    FilenameTyper filenameTyper;
    FilenameBox filenameBox;

    std::string label;
    sf::RenderWindow window;
    sf::Event event;
public:
    FilenameWindow();

    std::string run();
    std::string getLabel();

};


#endif //LOGOMAKER_FILENAMEWINDOW_H
