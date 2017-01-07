//
// Created by zairai on 25/11/16.
//

#include <iostream>
#include "WalkableNode.h"

WalkableNode::WalkableNode(int x, int y) : posX(x) , posY(y) {
    if(!texture.loadFromFile("img/ground_one.png"))
    {
        std::cout<<"Error";
    }
    value = 1;
    sprite = new sf::Sprite(texture);
    sprite->setPosition(50*posX,50*posY);
}

WalkableNode * WalkableNode::operator =(WalkableNode &rhs) {
    return new WalkableNode(rhs.posX , rhs.posY);
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

