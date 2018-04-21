//
// Created by wojoinc on 11/10/17.
//

#ifndef ROUGELIKE_PC_H
#define ROUGELIKE_PC_H

#include "ncurses.h"
#include "Character.h"

class PC : Character {
public:
    PC(Coordinate &start, unsigned char _symbol) {
        this->_symbol = _symbol;
        this->_start = &start;
    }

    PC(Floor *floor) {
        this->_start = new Coordinate(STARTX, STARTY);
        this->_loc = this->_start;
        this->_symbol = '@';
        this->_floor = floor;
    }

    void move(unsigned int y, unsigned int x);

    virtual ~PC();
};


#endif //ROUGELIKE_PC_H
