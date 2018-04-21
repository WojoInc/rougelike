//
// Created by wojoinc on 4/21/18.
//

#include "Floor.h"

/**
 * For now, just check if cell is empty.
 * //TODO Take character attributes into account
 * @param c
 * @param loc
 * @return
 */
bool Floor::canMove(Character &c, Coordinate loc) {
    return cellAt(loc)->isEmpty();
}

Cell *Floor::cellAt(Coordinate loc) {
    return &_cells[loc.get_y() * _width + loc.get_x()];
}

Floor::Floor(unsigned int _height, unsigned int _width) : _width(_width), _height(_height) {
    _cells = new Cell[_width * _height];
    for (unsigned int i = 0; i < _height; ++i) {
        for (unsigned int j = 0; j < _width; ++j) {
            _cells[i * _width + j] = Cell(new Coordinate(j, i));
        }
    }
}

void Floor::moveTo(Character *c, Coordinate loc) {
    //TODO does this need to check if cell is empty or do we trust the rest of the code will check before calling this?
    cellAt(*c->get_loc())->exit();
    c->set_loc(loc);
    cellAt(loc)->enter(c);
}
