#include <iostream>
#include <SFML/Graphics.hpp>
#include "MenuBar.h"
#include "SettingMenu.h"
#include "Slider.h"
#include "LogoMaker.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1200, 1000, 32), "Logo Maker");
    window.setFramerateLimit(60);
    // std::cout << window.getSize().x;
    LogoMaker logoMaker;
    //logoMaker.setPosition(1,1);

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            logoMaker.addEventHandler(window, event);
        }
        logoMaker.update();
        window.clear();
        window.draw(logoMaker);
        window.display();
    }
    return 0;
}
