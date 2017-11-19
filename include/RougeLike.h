//
// Created by wojoinc on 11/8/17.
//

#ifndef ROUGELIKE_ROUGELIKE_H
#define ROUGELIKE_ROUGELIKE_H


#include "vector"
#include "main.h"
#include "PC.h"
#include "Floor.h"

#define PSTARTX 10;
#define PSTARTY 10;

class RougeLike {
private:
    PC *_pc;
    std::vector<Floor *> *floors;

    void cleanupFloors();
public:
    RougeLike() {
        this->_pc = new PC();
        this->floors = new std::vector<Floor *>(255);
        Floor::generateFloors(floors);
        floors->at(0)->draw();
    }


    virtual ~RougeLike();

    int main_loop();

};


#endif //ROUGELIKE_ROUGELIKE_H
