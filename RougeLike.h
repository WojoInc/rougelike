//
// Created by wojoinc on 11/8/17.
//

#ifndef ROUGELIKE_ROUGELIKE_H
#define ROUGELIKE_ROUGELIKE_H


#include "main.h"
#include "PC.h"
#include "Floor.h"

#define PSTARTX 10;
#define PSTARTY 10;

class RougeLike {
private:
    PC *_pc;
    Floor *_floor;
public:
    RougeLike();

    virtual ~RougeLike();

    int main_loop();

};


#endif //ROUGELIKE_ROUGELIKE_H
