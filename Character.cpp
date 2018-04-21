//
// Created by wojoinc on 4/21/18.
//

#include "Character.h"

unsigned char Character::get_symbol() const {
    return _symbol;
}

Coordinate *Character::get_loc() const {
    return _loc;
}

Character::~Character() {}

void Character::set_loc(Coordinate _loc) {
    *this->_loc = _loc;
}




