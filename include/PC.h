//
// Created by wojoinc on 11/10/17.
//

#ifndef ROUGELIKE_PC_H
#define ROUGELIKE_PC_H

#include "ncurses.h"
#include "stdef.h"
#include "Cell.h"
#include "Floor.h"

#define PSTARTX 10;
#define PSTARTY 10;

class PC {
private:
    Cell *loc, *start_loc;
    byte_t _start_x;
    byte_t _start_y;
    byte_t _x, _y;
    byte_t _symbol;
    Floor *currentFloor;

public:
    PC(byte_t _start_x, byte_t _start_y, byte_t _symbol) {
        this->_x = this->_start_x = _start_x;
        this->_y = this->_start_y = _start_y;
        this->_symbol = _symbol;
    }

    PC(Cell *start_loc, byte_t symbol) {
        //TODO set x and y
        this->loc = this->start_loc = start_loc;
        this->_y = this->start_loc->get_y();
        this->_x = this->start_loc->get_x();
        this->_symbol = symbol;
    }

    void move(char y, char x);

    void move(Cell *cell);

    Floor *getCurrentFloor() const;

    void setCurrentFloor(Floor *currentFloor);

};


#endif //ROUGELIKE_PC_H
