//
// Created by wojoinc on 11/11/17.
//

#ifndef ROUGELIKE_FLOOR_H
#define ROUGELIKE_FLOOR_H

#include "stdef.h"
#include <vector>
#include "Cell.h"
#include "Drawable.h"


class Floor : Drawable {

private:
    byte_t _width, _height;
    byte_t _order;

    std::vector<Cell *> *_cells;

public:
    Floor(byte_t width, byte_t height, byte_t order) {
        this->_width = width;
        this->_height = height;
        this->_order = order;
        this->_cells = new std::vector<Cell *>(this->_height * this->_width);
        Cell::generateCells(this->_cells, this->_height, this->_width);
    }

    Floor(byte_t order) {
        this->_height = this->_width = 255;
        this->_order = order;
        this->_cells = new std::vector<Cell *>(this->_height * this->_width);
        Cell::generateCells(this->_cells, this->_height, this->_width);
    }

    static void generateFloors(std::vector<Floor *> *floors);

    void draw();

    void testDraw();

    Cell *cellAt(byte_t y, byte_t x);

};


#endif //ROUGELIKE_FLOOR_H
