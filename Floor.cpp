//
// Created by wojoinc on 11/11/17.
//

#include <vector>
#include "Floor.h"

void Floor::generateFloors(std::vector<Floor *> *floors) {
    for (auto itr = floors->begin(); itr != floors->end(); ++itr) {
        *itr = new Floor(1);
    }
}