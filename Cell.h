//
// Created by wojoinc on 4/21/18.
//

#ifndef ROUGELIKE_CELL_H
#define ROUGELIKE_CELL_H


#include "Character.h"
#include "Coordinate.h"

class Character;

class Cell {
    char symbol = '#';
    //for now, only have a slot for characters, eventually cell can contain items etc,
    Character *c;
    Coordinate *loc;
public:
    Cell() = default;

    Cell(Coordinate *loc) : loc(loc) {
        c = nullptr;
    }

    char getSymbol() const;

    void setSymbol(char symbol);

    /**
     * For now only characters can enter
     * @param c
     */
    void enter(Character *c);

    void exit();

    bool isEmpty();


};


#endif //ROUGELIKE_CELL_H
