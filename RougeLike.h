//
// Created by wojoinc on 11/8/17.
//

#ifndef ROUGELIKE_ROUGELIKE_H
#define ROUGELIKE_ROUGELIKE_H


#include "main.h"

#define PSTARTX 10;
#define PSTARTY 10;

class RougeLike {
private:
    unsigned char p_start_x;
    unsigned char p_start_y;
    unsigned char p_x, p_y;
public:
    RougeLike(unsigned char x, unsigned char y) {
        p_start_x = x;
        p_start_y = y;
        p_x = x;
        p_y = y;
    }

    RougeLike() {
        p_x = p_start_x = PSTARTX;
        p_y = p_start_y = PSTARTY;
    }

    int main_loop();

};


#endif //ROUGELIKE_ROUGELIKE_H
