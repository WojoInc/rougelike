//
// Created by wojoinc on 11/10/17.
//

#ifndef ROUGELIKE_PC_H
#define ROUGELIKE_PC_H

#include "ncurses.h"
#include "stdef.h"

#define PSTARTX 10;
#define PSTARTY 10;

class PC {
private:
    byte_t _start_x;
    byte_t _start_y;
    byte_t _x, _y;
    byte_t _symbol;

public:
    PC(byte_t _start_x, byte_t _start_y, byte_t _symbol) {
        this->_x = this->_start_x = _start_x;
        this->_y = this->_start_y = _start_y;
        this->_symbol = _symbol;
    }

    PC() {
        this->_x = this->_start_x = PSTARTX;
        this->_y = this->_start_y = PSTARTY;
        this->_symbol = '@';
    }

    void move(char y, char x);

};


#endif //ROUGELIKE_PC_H
