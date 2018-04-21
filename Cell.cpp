//
// Created by wojoinc on 4/21/18.
//

#include "main.h"
#include "Cell.h"

char Cell::getSymbol() const {
    return symbol;
}

void Cell::setSymbol(char symbol) {
    Cell::symbol = symbol;
}

/**
 * For now just check that there is no character in the cell
 * @return
 */
bool Cell::isEmpty() {
    return c == nullptr;
}

void Cell::enter(Character *c) {
    this->c = c;
    mvaddch(loc->get_y(), loc->get_x(), this->c->get_symbol());
}

void Cell::exit() {
    c = nullptr;
    mvaddch(loc->get_y(), loc->get_x(), symbol);
}
