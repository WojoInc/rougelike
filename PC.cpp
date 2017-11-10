//
// Created by wojoinc on 11/10/17.
//

#include "PC.h"

void PC::move(char y, char x) {
    mvaddch(this->_y, this->_x, ' ');
    mvaddch(this->_y += y, this->_x += x, this->_symbol);
}
