//
// Created by root on 8/10/17.
//

#ifndef ROUGELIKE_GAMEOBJECT_H
#define ROUGELIKE_GAMEOBJECT_H


#include "../Graphics.h"
#include "../dungeon/Dungeon.h"
#include <string>

class GameObject {
protected:
    unsigned int d_height, d_width;
    unsigned int d_x, d_y;
    char* sprite;
    Dungeon *dungeon;
public:
    GameObject(Dungeon *dungeon) : dungeon(dungeon) {};
    void draw();
    void erase();
};


#endif //ROUGELIKE_GAMEOBJECT_H
