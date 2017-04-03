//
// Created by zairai on 25/11/16.
//

#ifndef PATHFINDER_GROUND_H
#define PATHFINDER_GROUND_H


#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "Terrain.h"

class Ground : public Terrain {
public:
    Ground(int x , int y , int v);
    Ground(const Ground& rhs);
    int getValue();
    int getX();
    int getY();
    Ground * operator = (Ground& rhs);
    sf::Sprite * getSprite();
    void trackedPath(int x , int y , sf::Sprite * sprite);
private:
    int posX;
    int posY;
    int value;
    sf::Texture texture;
    sf::Sprite * sprite;
};


#endif //PATHFINDER_GROUND_H
