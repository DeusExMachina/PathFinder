//
// Created by zairai on 07/01/17.
//

#include "UnwalkableNode.h"
#include <iostream>

UnwalkableNode::UnwalkableNode(int x, int y) : posX(x) , posY(y){
    if(!texture.loadFromFile("img/ground_nine.png"))
    {
        std::cout<<"Error";
    }
    value = 9;
    sprite = new sf::Sprite(texture);
    sprite->setPosition(50*posX,50*posY);
}

UnwalkableNode * UnwalkableNode::operator =(UnwalkableNode &rhs) {
    return new UnwalkableNode(rhs.posX , rhs.posY);
}

UnwalkableNode::UnwalkableNode(const UnwalkableNode& rhs) {
    posX = rhs.posX;
    posY = rhs.posY;
    value = rhs.value;
}

int UnwalkableNode::getX() {
    return posX;
}

int UnwalkableNode::getY() {
    return posY;
}

int UnwalkableNode::getValue() {
    return value;
}

sf::Sprite *UnwalkableNode::getSprite() {
    return sprite;
}