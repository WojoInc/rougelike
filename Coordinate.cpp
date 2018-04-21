//
// Created by wojoinc on 4/21/18.
//

#include "Coordinate.h"

Coordinate::Coordinate(unsigned int _x, unsigned int _y) : _x(_x), _y(_y) {}

unsigned int Coordinate::get_x() const {
    return _x;
}

void Coordinate::set_x(unsigned int _x) {
    Coordinate::_x = _x;
}

unsigned int Coordinate::get_y() const {
    return _y;
}

void Coordinate::set_y(unsigned int _y) {
    Coordinate::_y = _y;
}
