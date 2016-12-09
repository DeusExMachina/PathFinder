//
// Created by zairai on 09/12/16.
//

#ifndef PATHFINDER_GAMECHARACTER_H
#define PATHFINDER_GAMECHARACTER_H


class GameCharacter {
public:
    GameCharacter(int posX , int posY , int hp);
    GameCharacter(const GameCharacter& rhs);
    GameCharacter * operator = (GameCharacter& rhs);
private:
};


#endif //PATHFINDER_GAMECHARACTER_H
