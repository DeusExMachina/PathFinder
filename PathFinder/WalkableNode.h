//
// Created by zairai on 25/11/16.
//

#ifndef PATHFINDER_WALKABLENODE_H
#define PATHFINDER_WALKABLENODE_H


#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "Terrain.h"

class WalkableNode : public Terrain {
public:
    WalkableNode(int x , int y , int value);
    WalkableNode(const WalkableNode& rhs);
    int getValue();
    int getX();
    int getY();

    WalkableNode * operator = (WalkableNode& rhs);

    sf::Sprite * getSprite();
private:
    int posX;
    int posY;
    int value;
    sf::Texture texture;
    sf::Sprite * sprite;
};


#endif //PATHFINDER_WALKABLENODE_H
