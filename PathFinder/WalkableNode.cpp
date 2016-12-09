//
// Created by zairai on 25/11/16.
//

#include <iostream>
#include "WalkableNode.h"

WalkableNode::WalkableNode(int x, int y , int v) : posX(x) , posY(y) , value(v) {
    if(!texture.loadFromFile("img/red.png"))
    {
        std::cout<<"Error";
    }
    sprite = new sf::Sprite(texture);
    sprite->setPosition(50*posX,50*posY);
}

WalkableNode * WalkableNode::operator =(WalkableNode &rhs) {
    return new WalkableNode(rhs.posX , rhs.posY , rhs.value);
}

WalkableNode::WalkableNode(const WalkableNode& rhs) {
    posX = rhs.posX;
    posY = rhs.posY;
    value = rhs.value;
}

int WalkableNode::getX() {
    return posX;
}

int WalkableNode::getY() {
    return posY;
}

int WalkableNode::getValue() {
    return value;
}

sf::Sprite *WalkableNode::getSprite() {
    return sprite;
}

