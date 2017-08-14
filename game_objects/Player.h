//
// Created by root on 8/10/17.
//

#ifndef ROUGELIKE_PLAYER_H
#define ROUGELIKE_PLAYER_H

#include <cstdlib>
#include "GameObject.h"

class Player : public GameObject{
public:
    Player(Dungeon *dungeon) : GameObject(dungeon) {
        sprite = (char*)malloc(sizeof(char));
        *sprite = '@';
        d_height = d_width = 1;
        d_x = d_y = 0;
    }

    void move_abs(unsigned int x, unsigned int y){
        erase();
        d_x = x;
        d_y = y;
        draw();
        refresh();
    }
    void move_rel(int x, int y){
        erase();
        d_x += x;
        d_y += y;
        draw();
        refresh();
    }

    ~Player(){}
};


#endif //ROUGELIKE_PLAYER_H
