//
// Created by wojoinc on 11/11/17.
//

#include <ncurses.h>
#include "../include/Floor.h"

void Floor::generateFloors(std::vector<Floor *> *floors) {
    for (auto itr = floors->begin(); itr != floors->end(); ++itr) {
        *itr = new Floor(1);
    }
}

void Floor::generateCells() {

    for (auto itr = this->_cells->begin(); itr != this->_cells->end(); ++itr) {
        *itr = new Cell;
    }

}

void Floor::draw() {
    byte_t y = 0, x = 0;
    for (auto itr = this->_cells->begin(); itr != this->_cells->end(); ++itr) {
        mvaddch(y, x++, 94);
        if (x == 255 && y <= 255) {
            x = 0;
            ++y;
        }
    }
}