//
// Created by zairai on 07/01/17.
//

#ifndef PATHFINDER_UNWALKABLENODE_H
#define PATHFINDER_UNWALKABLENODE_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "Terrain.h"

class UnwalkableNode : public Terrain {
public:
    UnwalkableNode(int x , int y);
    UnwalkableNode(const UnwalkableNode& rhs);
    int getValue();
    int getX();
    int getY();

    UnwalkableNode * operator = (UnwalkableNode& rhs);

    sf::Sprite * getSprite();
private:
    int posX;
    int posY;
    int value;
    sf::Texture texture;
    sf::Sprite * sprite;
};


#endif //PATHFINDER_UNWALKABLENODE_H
