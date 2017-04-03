//
// Created by zairai on 25/11/16.
//

#ifndef PATHFINDER_TERRAIN_H
#define PATHFINDER_TERRAIN_H

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

class Terrain {
public:
    virtual int getValue() = 0;
    virtual int getX() = 0;
    virtual int getY() = 0;
    virtual sf::Sprite * getSprite() = 0;
    virtual void trackedPath(int x , int y , sf::Sprite * sprite) = 0;
};


#endif //PATHFINDER_TERRAIN_H
