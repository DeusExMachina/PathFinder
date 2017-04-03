//
// Created by zairai on 25/11/16.
//

#ifndef PATHFINDER_MAP_H
#define PATHFINDER_MAP_H


#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Ground.h"

class Map {
public:
    static Map& get_instance();
    void display();
    int getSelectedCell(int x , int y);
    int loadFromTxt();
    sf::Sprite * getSelectedSprite(int x , int y);
    int startPF(int startX, int startY, int endX , int endY );
    Terrain* getGround(int x , int y);
private:
    Map();
    Map(const Map&);
    void operator=(const Map&);

    std::vector<Terrain *> tile;
    sf::RenderWindow * window;
    int width;
    int height;
};


#endif //PATHFINDER_MAP_H
