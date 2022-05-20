//
// Created by Chan Lee on 2022-04-30.
//

#include "FilenameWindow.h"
FilenameWindow::FilenameWindow()
{
    filenameTyper.setLength(500);
    filenameTyper.setSize(500, 400);
    filenameBox.setString("Export");
    filenameBox.setPosition(filenameTyper.getPosition().x + filenameTyper.getGlobalBound().width/2,
                            filenameTyper.getPosition().y + filenameTyper.getGlobalBound().height + 40);
}

std::string FilenameWindow::run()
{
    window.create(sf::VideoMode({504,500}), "Exporting Image");
    filenameTyper.setPosition({2,2});
    while(window.isOpen())
    {
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if(MouseEvents<FilenameBox>::mouseClicked(filenameBox, window))
            {
                label = filenameTyper.getString();
                window.close();
            }
            else if(MouseEvents<FilenameBox>::hovered(filenameBox, window))
            {
                filenameBox.setFillColor({50,50,80});
            }
            else
            {
                filenameBox.setFillColor({55,55,55,255});
            }
            filenameTyper.addEventHandler(window, event);
        }
        filenameTyper.update();
        window.clear();
        window.draw(filenameTyper);
        window.draw(filenameBox);
        window.display();
    }
    States::setMenuEnable(EXPORT_PROJECT, false);
}

std::string FilenameWindow::getLabel()
{
    return label;
}
