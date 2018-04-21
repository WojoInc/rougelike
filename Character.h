//
// Created by wojoinc on 4/21/18.
//

#ifndef ROUGELIKE_CHARACTER_H
#define ROUGELIKE_CHARACTER_H

#include "Coordinate.h"
#include "Floor.h"

class Floor;

class Character {
protected:
    const unsigned int STARTX = 10, STARTY = 10;
    unsigned char _symbol;
    Coordinate *_start;
    Coordinate *_loc;
    Floor *_floor;
public:
    virtual ~Character() = 0;

    virtual void move(unsigned int y, unsigned int x)= 0;

    unsigned char get_symbol() const;

    Coordinate *get_loc() const;

    void set_loc(Coordinate _loc);
};


#endif //ROUGELIKE_CHARACTER_H
