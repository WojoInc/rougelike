//
// Created by wojoinc on 11/11/17.
//

#ifndef ROUGELIKE_FLOOR_H
#define ROUGELIKE_FLOOR_H

#include "stdef.h"
#include "Cell.h"

class Floor {

private:
    byte_t _width, _height;
    byte_t _order;

    std::vector<Cell *> *_cells;


public:
    Floor(byte_t width, byte_t height, byte_t order) {
        this->_width = width;
        this->_height = height;
        this->_order = order;
    }

    Floor(byte_t order) {
        this->_height = this->_width = 255;
        this->_order = order;
    }

    static void generateFloors(std::vector<Floor *> *floors);


};


#endif //ROUGELIKE_FLOOR_H
