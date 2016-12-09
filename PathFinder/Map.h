//
// Created by zairai on 25/11/16.
//

#ifndef PATHFINDER_MAP_H
#define PATHFINDER_MAP_H


#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>
#include "WalkableNode.h"

class Map {
public:
    static Map& get_instance();
    void init();
    void printNodeInfo();
    void startPathfinding();
    void display();
    void selectedCell(int x , int y);
    int getSelectedCell(int x , int y);
    sf::Sprite * getSelectedSprite(int x , int y);
private:
    Map();;
    Map(const Map&);
    void operator=(const Map&);

    std::vector<Terrain *> green_node;
    sf::RenderWindow * window;
    int width;
    int height;
};


#endif //PATHFINDER_MAP_H
