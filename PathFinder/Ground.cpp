//
// Created by zairai on 25/11/16.
//

#include <iostream>
#include "Ground.h"

Ground * Ground::operator =(Ground &rhs) {
    return new Ground(rhs.posX , rhs.posY , rhs.value);
}

Ground::Ground(const Ground& rhs) {
    posX = rhs.posX;
    posY = rhs.posY;
    value = rhs.value;
}

int Ground::getX() {
    return posX;
}

int Ground::getY() {
    return posY;
}

int Ground::getValue() {
    return value;
}

sf::Sprite *Ground::getSprite() {
    return sprite;
}

Ground::Ground(int x, int y, int v): posX(x) , posY(y) , value(v){
    if(!texture.create(50,50)) {
        //error
    }
    sf::Image image;
    if(v == 1)
    {
        image.create(50,50,sf::Color::Green);
        texture.update(image);
    }
    else if(v == 2) {
        image.create(50,50,sf::Color::Yellow);
        texture.update(image);
    }
    else if(v == 3) {
        image.create(50,50,sf::Color(255,165,0));
        texture.update(image);
    }
    else if(v == 4) {
        image.create(50,50,sf::Color::Red);
        texture.update(image);
    }
    else if(v == 5) {
        image.create(50,50,sf::Color::Magenta);
        texture.update(image);
    }
    else if(v == 6) {
        image.create(50,50,sf::Color::Blue);
        texture.update(image);
    }
    else if(v == 7) {
        image.create(50,50,sf::Color(75,0,130));
        texture.update(image);
    }
    else if(v == 8) {
        image.create(50,50,sf::Color(143,0,255));
        texture.update(image);
    }
    else if(v == 9) {
        image.create(50,50,sf::Color::Black);
        texture.update(image);
    }
    sprite = new sf::Sprite(texture);
    sprite->setPosition(50*posX,50*posY);
}

void Ground::trackedPath(int x , int y , sf::Sprite *sprite) {
    sf::Image image;
    image.create(25,25,sf::Color::Red);
    texture.update(image);
    sprite->setTexture(texture);
}



