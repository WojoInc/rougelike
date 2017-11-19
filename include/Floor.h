//
// Created by wojoinc on 11/11/17.
//

#ifndef ROUGELIKE_FLOOR_H
#define ROUGELIKE_FLOOR_H

#include "stdef.h"
#include <vector>
#include "Cell.h"


class Floor {

private:
    byte_t _width, _height;
    byte_t _order;

    std::vector<Cell *> *_cells;

    void generateCells();


public:
    Floor(byte_t width, byte_t height, byte_t order) {
        this->_width = width;
        this->_height = height;
        this->_order = order;
        this->_cells = new std::vector<Cell *>(this->_height * this->_width);
        this->generateCells();
    }

    Floor(byte_t order) {
        this->_height = this->_width = 255;
        this->_order = order;
        this->_cells = new std::vector<Cell *>(this->_height * this->_width);
        this->generateCells();
    }

    static void generateFloors(std::vector<Floor *> *floors);

    void draw();

};


#endif //ROUGELIKE_FLOOR_H
