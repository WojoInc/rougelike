//
// Created by wojoinc on 11/13/17.
//

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
