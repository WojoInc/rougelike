//
// Created by wojoinc on 11/11/17.
//

#include "../include/Floor.h"

void Floor::generateFloors(std::vector<Floor *> *floors) {
    for (auto itr = floors->begin(); itr != floors->end(); ++itr) {
        *itr = new Floor(1);
    }
}

void Floor::draw() {
    for (auto itr = this->_cells->begin(); itr != this->_cells->end(); ++itr) {
        (*itr)->draw();
    }
}

void Floor::testDraw() {
    for (auto itr = this->_cells->begin(); itr != this->_cells->end(); ++itr) {
        (*itr)->testDraw();
    }
}

Cell *Floor::cellAt(byte_t y, byte_t x) {
    return this->_cells->at(this->_width * y + x);
}
