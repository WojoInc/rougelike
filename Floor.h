//
// Created by wojoinc on 4/21/18.
//

#ifndef ROUGELIKE_FLOOR_H
#define ROUGELIKE_FLOOR_H

#include "Coordinate.h"
#include "Cell.h"

class Character;

class Cell;

class Floor {
private:
    Cell *_cells;
    unsigned int _width, _height;
public:
    Floor(unsigned int _height, unsigned int _width);

    bool canMove(Character &c, Coordinate loc);

    void moveTo(Character *c, Coordinate loc);

    Cell *cellAt(Coordinate loc);
};


#endif //ROUGELIKE_FLOOR_H
