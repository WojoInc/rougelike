//
// Created by root on 8/10/17.
//


#include <ncurses.h>
#include "Dungeon.h"

int distance2(int x1, int y1, int x2, int y2) {
    return ((x2 - x1) ^ 2) + ((y2 - y1) ^ 2);
}

Dungeon::Dungeon(unsigned int height, unsigned int width, unsigned int rooms)
        : d_height(height), d_width(width), n_rooms(rooms) {

    //allocate cells
    cells = new Cell *[d_height * d_width];
    for (unsigned int i = 0; i < d_height; i++) {
        for (unsigned int j = 0; j < d_width; j++) {
            cells[(d_width * i) + j] = new Cell(j, i, rand() % 255);
            mvaddch(i, j, cells[(d_width * i) + j]->getSymbol());
        }
    }

    Dungeon::rooms = new Room *[n_rooms];
    for (int i = 0; i < n_rooms; ++i) {
        Dungeon::rooms[i] = new Room(0, 0, 0, 0);
    }
    fillCells();
    //placeRooms();

}

void Dungeon::fillCells() {

    //Randomly assign attributes to cells
    for (unsigned int i = 0; i < d_height; i++) {
        for (unsigned int j = 0; j < d_width; j++) {
            //if cell is the border of the dungeon, set the border attribute
            if ((i == 0) || (j == 0)) cells[(d_width * i) + j]->setBorder(true);
        }
    }
}

void Dungeon::placeRooms() {
    unsigned int x, y, width, height, i = 0, j = 0, num_failed = 0;
    bool valid = false;
    //allow up to 20 failures to place a room. Avoids trying to place additional
    // rooms if space is too constrained, or no possible room exists. Resets after each successful placement
    while (i < n_rooms && num_failed < 20) {
        x = rand() % d_width + 1; //+1 to account for top and left borders
        y = rand() % d_height + 1;
        width = rand() % MAX_DIM + MIN_DIM;
        height = rand() % MAX_DIM + MIN_DIM;

        //check if proposed room is within dungeon borders
        if ((x < (d_width - 1)) && (y < (d_height - 1)) && ((x + width) < (d_width - 1)) &&
            ((y + height) < (d_height - 1))) {

            while (j < n_rooms) {
                /*if rooms[j] has not been placed, assume successful and break from loop
                 *We can do this as we will have already checked all the placed rooms,
                 * and an unplaced room means that we have no more rooms to check, as they are either from
                 * a previous floor, or this is the first floor and they have not been validated and placed
                 * yet.
                 */
                if (!rooms[j]->isPlaced()) {
                    valid = true;
                    break;
                }

                Room temp = Room(x, y, height, width);
                unsigned int x1, x2, y1, y2;
                /*
                 * Compare the distance between the centers of the two rooms.
                 * If less than the sum of the distance between the center of each room to
                 * its respective corner. We have encountered an overlap. This is overkill
                 * for rooms placed side by side, but accuracy isn't important here.
                 * +1 is added to make sure there is at least one cell between the rooms.
                 */
                rooms[j]->getCenter(&x1, &y1);
                temp.getCenter(&x2, &y2);
                int d1 = distance2(x1, y1, x2, y2);
                int d2 = distance2(temp.getD_x(), temp.getD_y(), x2, y2);
                int d3 = distance2(rooms[j]->getD_x(), rooms[j]->getD_y(), x1, y1);
                if (d1 > (d2 + d3 + 1)) { valid = true; }
                else {
                    valid = false;
                    break;
                }//this means we have encountered an overlap

            }

        }

        if (valid) {
            rooms[i]->setD_x(x);
            rooms[i]->setD_y(y);
            rooms[i]->setD_height(height);
            rooms[i]->setD_width(width);
            rooms[i]->setPlaced(true);
        }

    }

}

void Room::getCenter(unsigned int *x, unsigned int *y) {
    *x = d_x + d_width / 2;
    *y = d_y + d_height / 2;
}
