#include "Map.h"

int main() {
    Map::get_instance().loadFromTxt();
    Map::get_instance().display();
    return 0;
}