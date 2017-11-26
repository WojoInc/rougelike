//
// Created by wojoinc on 11/13/17.
//

#ifndef ROUGELIKE_CELL_H
#define ROUGELIKE_CELL_H


#include <stdlib.h>
#include <vector>
#include "stdef.h"
#include "Drawable.h"

class Cell : Drawable {

public:
    enum CELL_TYPE {
        ROCK = '=',
        ROOM_STD = '.',
        ROOM_STAIR_UP = '>',
        ROOM_STAIR_DOWN = '<',
        CORRIDOR = '#'
    };
    enum CELL_ATTR {
        NONE = 0x0
    };
private:
    byte_t _hardness;
    CELL_TYPE _type;
    CELL_ATTR _attr;
    byte_t _y, _x;
    bool _occupied;

public:
    CELL_TYPE get_type() const;

    void set_type(CELL_TYPE _type);

    CELL_ATTR get_attr() const;

    void set_attr(CELL_ATTR _attr);

    byte_t get_hardness() const;

    void set_hardness(byte_t _hardness);

    bool isOccupied() const;

    bool occupy(byte_t symbol);

    bool unoccupy();

    Cell(byte_t y, byte_t x) {
        this->_hardness = rand() % 255;
        this->_attr = NONE;
        this->_type = CELL_TYPE::ROCK;
        this->_y = y;
        this->_x = x;
        this->_occupied = false;
    }

    void draw();

    void testDraw();

    byte_t get_y() const;

    void set_y(byte_t _y);

    byte_t get_x() const;

    void set_x(byte_t _x);

    static void generateCells(std::vector<Cell *> *cells, byte_t height, byte_t width);
};


#endif //ROUGELIKE_CELL_H
