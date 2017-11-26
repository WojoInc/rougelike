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

        this->floors = new std::vector<Floor *>(255);
        Floor::generateFloors(floors);
        floors->at(0)->testDraw();
        this->_pc = new PC(floors->at(0)->cellAt(10, 10), '@');
        this->_pc->setCurrentFloor(floors->at(0));
    }


    virtual ~RougeLike();

    int main_loop();

};


#endif //ROUGELIKE_ROUGELIKE_H
