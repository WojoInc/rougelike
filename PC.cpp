//
// Created by wojoinc on 11/10/17.
//

#include "PC.h"

void PC::move(unsigned int y, unsigned int x) {
    /*mvaddch(this->_y, this->_x, ' ');
    mvaddch(this->_y += y, this->_x += x, this->_symbol);*/
    //TODO Save the headache and add a vector or something to the Coordinate class
    Coordinate dest = Coordinate(this->_loc->get_x() + x, this->_loc->get_y() + y);
    if (_floor->canMove(*this, dest)) {
        _floor->moveTo(this, dest);
    }
}

PC::~PC() {
    delete (_loc);
    delete (_start);

}
