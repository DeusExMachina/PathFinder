#include <SFML/Graphics.hpp>
#include <iostream>
#include "Map.h"

int main() {
    sf::Clock clock;
    clock.getElapsedTime();
    for(;;)
    {
        if(clock.getElapsedTime().asSeconds() == 2.0f) {
            std::cout << "Tempo trascorso : 10 sec" << std::endl;
            break;
        }
    }
    Map::get_instance().init();
    Map::get_instance().display();

    return 0;
}