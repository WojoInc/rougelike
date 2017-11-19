//
// Created by wojoinc on 11/13/17.
//

#ifndef ROUGELIKE_CELL_H
#define ROUGELIKE_CELL_H


#include <stdlib.h>
#include "stdef.h"

class Cell {

public:
    enum CELL_TYPE {
        ROCK,
        ROOM_STD,
        ROOM_STAIR_UP,
        ROOM_STAIR_DOWN,
        CORRIDOR
    };
    enum CELL_ATTR {
        NONE = 0x0
    };
private:
    byte_t _hardness;
    CELL_TYPE _type;
    CELL_ATTR _attr;

public:
    CELL_TYPE get_type() const;

    void set_type(CELL_TYPE _type);

    CELL_ATTR get_attr() const;

    void set_attr(CELL_ATTR _attr);

    byte_t get_hardness() const;

    void set_hardness(byte_t _hardness);

    Cell() {
        this->_hardness = rand() % 255;
        this->_attr = NONE;
        this->_type = CELL_TYPE::ROCK;
    }
};


#endif //ROUGELIKE_CELL_H
