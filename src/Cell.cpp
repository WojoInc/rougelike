//
// Created by wojoinc on 11/13/17.
//

#include <ncurses.h>
#include "../include/Cell.h"

byte_t Cell::get_hardness() const {
    return _hardness;
}

void Cell::set_hardness(byte_t _hardness) {
    Cell::_hardness = _hardness;
}

Cell::CELL_TYPE Cell::get_type() const {
    return _type;
}

void Cell::set_type(Cell::CELL_TYPE _type) {
    Cell::_type = _type;
}

Cell::CELL_ATTR Cell::get_attr() const {
    return _attr;
}

void Cell::set_attr(Cell::CELL_ATTR _attr) {
    Cell::_attr = _attr;
}

void Cell::testDraw() {
    if (this->_hardness < 50) mvaddch(this->_y, this->_x, '0');
    else if (this->_hardness < 100) mvaddch(this->_y, this->_x, '1');
    else if (this->_hardness < 150) mvaddch(this->_y, this->_x, '2');
    else if (this->_hardness < 200) mvaddch(this->_y, this->_x, '3');
    else if (this->_hardness < 255) mvaddch(this->_y, this->_x, '4');
}

void Cell::generateCells(std::vector<Cell *> *cells, byte_t height, byte_t width) {
    for (byte_t y = 0; y < height; y++) {
        for (byte_t x = 0; x < width; x++) {
            cells->at(y * width + x) = new Cell(y, x);
        }
    }

}

void Cell::draw() {
    mvaddch(this->_y, this->_x, this->_type);
}

bool Cell::isOccupied() const {
    return this->_occupied;
}

bool Cell::unoccupy() {
    //TODO add some addtional gameplay functionalities?
    this->draw();
    this->_occupied = false;
    //This could return differently if we could not free cell etc.
    return !this->_occupied;
}

bool Cell::occupy(byte_t symbol) {
    if (!isOccupied()) {
        mvaddch(this->_y, this->_x, symbol);
        this->_occupied = true;
        return this->_occupied;
    } else return false;
}

byte_t Cell::get_y() const {
    return _y;
}

void Cell::set_y(byte_t _y) {
    Cell::_y = _y;
}

byte_t Cell::get_x() const {
    return _x;
}

void Cell::set_x(byte_t _x) {
    Cell::_x = _x;
}
