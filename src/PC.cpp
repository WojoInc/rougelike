//
// Created by wojoinc on 11/10/17.
//

#include "../include/PC.h"

void PC::move(char y, char x) {
    //TODO rework for error checking if cell is occupied or not moveable to
    if (this->loc->unoccupy()) {
        //if we were able to leave current cell
        this->_x += x;
        this->_y += y;
        this->loc = this->currentFloor->cellAt(this->_y, this->_x);
        this->loc->occupy(this->_symbol);
    }
}

void PC::move(Cell *cell) {

}

Floor *PC::getCurrentFloor() const {
    return currentFloor;
}

void PC::setCurrentFloor(Floor *currentFloor) {
    PC::currentFloor = currentFloor;
}
