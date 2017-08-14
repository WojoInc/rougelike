//
// Created by root on 8/10/17.
//

#ifndef ROUGELIKE_DUNGEON_H
#define ROUGELIKE_DUNGEON_H
//min and max dimesions for rooms.
//TODO give player control over the dimensions of rooms

#include <cstdlib>
#include <random>

static const unsigned int MIN_DIM = 7;
static const unsigned int MAX_DIM = 15;

class Cell{
private:
    unsigned int d_x, d_y;
    int hardness;
    char symbol;
    bool border;

public:
    Cell(unsigned int x, unsigned int y, int hardness)
            : d_x(x), d_y(y), hardness(hardness), symbol(' ') {
        border = false;
    }

    void setHardness(int hardness) {
        Cell::hardness = hardness;
    }

    void setSymbol(char symbol) {
        Cell::symbol = symbol;
    }

    int getHardness() const {
        return hardness;
    }

    char getSymbol() const {
        return symbol;
    }

    bool isBorder() const {
        return border;
    }

    void setBorder(bool border) {
        Cell::border = border;
    }
};

class Room {
private:
    unsigned int
            d_x,
            d_y,
            d_height,
            d_width;
    bool placed;
public:
    Room(unsigned int d_x, unsigned int d_y, unsigned int d_height, unsigned int d_width) :
            d_x(d_x), d_y(d_y), d_height(d_height), d_width(d_width), placed(false) {}

    bool isPlaced()const {return placed;}

    void setPlaced(bool value){ placed=value; }

    void getCenter(unsigned int *x, unsigned int *y);

    unsigned int getD_x() const {
        return d_x;
    }

    void setD_x(unsigned int d_x) {
        Room::d_x = d_x;
    }

    unsigned int getD_y() const {
        return d_y;
    }

    void setD_y(unsigned int d_y) {
        Room::d_y = d_y;
    }

    unsigned int getD_height() const {
        return d_height;
    }

    void setD_height(unsigned int d_height) {
        Room::d_height = d_height;
    }

    unsigned int getD_width() const {
        return d_width;
    }

    void setD_width(unsigned int d_width) {
        Room::d_width = d_width;
    }

};

class Dungeon {
private:
    unsigned int d_height, d_width;
    unsigned int n_rooms;
    Cell **cells;
    Room **rooms;
    void fillCells();
    void placeRooms();

public:
    Dungeon(unsigned int height, unsigned int width, unsigned int rooms);

    /**
     * Randomizes the cells, room placement, monsters, etc. without reallocating.
     * This makes transitions between floors easier
     */
    void randomize();

    /**
     * Returns the character value for a specific cell
     * Useful for redrawing the floor after moving character from one cell to another.
     * @return the character value that represents the tile
     */
    char chCellAt(unsigned int x, unsigned int y) {
        return cells[(d_width * y) + x]->getSymbol();
    }
};


#endif //ROUGELIKE_DUNGEON_H
