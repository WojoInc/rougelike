//
// Created by root on 8/10/17.
//


#include "Dungeon.h"

Dungeon::Dungeon(unsigned int height, unsigned int width, unsigned int rooms)
        : d_height(height), d_width(width), n_rooms(rooms){

    //allocate cells
    cells = new Cell* [d_height * d_width];
    for(unsigned int i = 0; i<d_height; i++) {
        for (unsigned int j = 0; j < d_width; j++) {
            cells[(d_width * i) + j] = new Cell(j, i, rand() % 255);
        }
    }

    Dungeon::rooms = new Room* [n_rooms];
    for (int i = 0; i < n_rooms; ++i) {
        Dungeon::rooms[i] = new Room(0,0,0,0);
    }
    fillCells();
    placeRooms();

}

void Dungeon::fillCells() {

    //Randomly assign attributes to cells
    for(unsigned int i = 0; i<d_height; i++){
        for(unsigned int j = 0; j <d_width; j++){
            //if cell is the border of the dungeon, set the border attribute
            if((i==0) || (j==0)) cells[(d_width*i)+j]->setBorder(true);
        }
    }
}

void Dungeon::placeRooms() {
    unsigned int x, y, width, height, i=0, j=0, num_failed=0;
    bool valid = false;
    //allow up to 20 failures to place a room. Avoids trying to place additional
    // rooms if space is too constrained, or no possible room exists. Resets after each successful placement
    while (i < n_rooms && num_failed < 20) {
        x = rand() % d_width +1; //+1 to account for top and left borders
        y = rand() % d_height +1;
        width = rand() % MAX_DIM + MIN_DIM;
        height = rand() % MAX_DIM + MIN_DIM;

        //check if proposed room is within dungeon borders
        if (x<(d_width-1) && y<(d_height-1) && (x+width)<(d_width-1) && (y+height)<(d_height-1)){
            //now check if it overlaps another room
            while(j < n_rooms){
                // if rooms[j] has not been placed, assume successful and break from loop
                //TODO better comments here
                if(!rooms[j]->isPlaced()) {valid = true; break;}
            }
        }

        if(valid){
            rooms[i]->setD_x(x);
            rooms[i]->setD_y(y);
            rooms[i]->setD_height(height);
            rooms[i]->setD_width(width);
            rooms[i]->setPlaced(true);
        }

    }

}

void Room::getCenter(unsigned int *x, unsigned int *y) {
    *x = d_x + d_width /2;
    *y = d_y + d_height /2;
}
