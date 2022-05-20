//
// Created by PC on 2022-04-21.
//

#include "ColorRGB.h"

ColorRGB::ColorRGB()
: ColorRGB(sf::Color::White)
{
}
ColorRGB::ColorRGB(sf::Color color)
{
    int height = 256;
    int width = 256;
    gradients.setPrimitiveType(sf::Points);
    gradients.resize(height*width);
    background.setSize({255,255});
    background.setFillColor(sf::Color::White);
    setColor(color);
}

void ColorRGB::setPosition(float x, float y)
{
    int height = gradients.getBounds().height+1;
    int width = gradients.getBounds().width+1;
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            sf::Vertex& vertex = gradients[i*256+j];
            vertex.position = sf::Vector2f(x+j,y+i);//rectangle
        }
    }
    background.setPosition(x, y);
}
void ColorRGB::setColor(sf::Color color)
{
    ///https://de.wikipedia.org/wiki/HSV-Farbraum#Umrechnung_HSV_in_RGB
    //set HSV
    int r = color.r;
    int g = color.g;
    int b = color.b;
    int height = 256;
    int width = 256;
    int max, min;

    if(r==255 && g==255 && b==255)
    {
        max = 255;
        min = 255;
    }
    else if(r==0 && g==0 && b==0)
    {
        max = 0;
        min = 0;
    }
    else
    {
        max = 255;
        min = 0;
    }
    int diff = max-min;
    int H;

    if(diff==0)
    {
        H = 0;
    }
    else if(max == r)
    {
        H = 60*((g-b)/diff % 6);
    }
    else if(max == g)
    {
        H = 60*((b-r)/diff + 2);
    }
    else
    {
        H = 60*((r-g)/diff + 4);
    }
    //converting HSV into RGB
    for(double i=0; i<height; i++)
    {
        for(double j=0; j<width; j++)
        {
            double V, S;
            S=j/255;
            V=i/255;

            //i*256+j//i=height
            int h = H/60;
            double f = (H/60 - h);
            double p = V * (1-S);
            double q = V * (1-S*f);
            double t = V * (1-S*(1-f));

            int convR, convG, convB;
            switch(h)
            {
                case 0:
                    convR = V*255;
                    convG = t*255;
                    convB = p*255;
                    gradients[i*256+j].color = sf::Color(convR, convG, convB);
                    gradients[i*256+j].position = sf::Vector2f(j, i);
                    break;
                case 1:
                    convR = q*255;
                    convG = V*255;
                    convB = t*255;
                    gradients[i*256+j].color = sf::Color(convR, convG, convB);
                    gradients[i*256+j].position = sf::Vector2f(j, i);
                    break;
                case 2:
                    convR = p*255;
                    convG = V*255;
                    convB = t*255;
                    gradients[i*256+j].color = sf::Color(convR, convG, convB);
                    gradients[i*256+j].position = sf::Vector2f(j, i);
                    break;
                case 3:
                    convR = p*255;
                    convG = q*255;
                    convB = V*255;
                    gradients[i*256+j].color = sf::Color(convR, convG, convB);
                    gradients[i*256+j].position = sf::Vector2f(j, i);
                    break;
                case 4:
                    convR = t*255;
                    convG = p*255;
                    convB = V*255;
                    gradients[i*256+j].color = sf::Color(convR, convG, convB);
                    gradients[i*256+j].position = sf::Vector2f(j, i);
                    break;
                case 6:
                    convR = V*255;
                    convG = t*255;
                    convB = p*255;
                    gradients[i*256+j].color = sf::Color(convR, convG, convB);
                    gradients[i*256+j].position = sf::Vector2f(j, i);
                    break;
                default:
                    convR = V*255;
                    convG = p*255;
                    convB = q*255;
                    gradients[i*256+j].color = sf::Color(convR, convG, convB);
                    gradients[i*256+j].position = sf::Vector2f(j, i);
                    break;
            }
            if(diff == 0)//left to right
            {
                convR = 255-j;
                convG = 255-j;
                convB = 255-j;
            }
            gradients[i*256+j].color = sf::Color(convR, convG, convB);
            gradients[i*256+j].position = sf::Vector2f(j, i);
        }
    }
}
sf::Color ColorRGB::getColor(sf::Vector2i position)
{
    int height = gradients.getBounds().height;
    int width = gradients.getBounds().width;
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            sf::Vertex&  vertex = gradients[i*256+j];
            if(vertex.position.x == position.x && vertex.position.y == position.y)
            {
                return vertex.color;
            }
        }
    }
}
sf::FloatRect ColorRGB::getGlobalBounds()
{
    return gradients.getBounds();
}

void ColorRGB::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
}
void ColorRGB::update()
{
}
void ColorRGB::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(background);
    window.draw(gradients);
}

Snapshot &ColorRGB::getSnapshot()
{
}
void ColorRGB::applySnapshot(const Snapshot &snapshot)
{
}
