//
// Created by wojoinc on 11/8/17.
//

#include "RougeLike.h"

int RougeLike::main_loop() {
    int ch = 0;
    int res = 1;

    while (res == 1) {
        ch = getch();
        switch (ch) {
            case 'w':
                this->_pc->move(-1, 0);
                break;
            case 's':
                this->_pc->move(1, 0);
                break;
            case 'a':
                this->_pc->move(0, -1);
                break;
            case 'd':
                this->_pc->move(0, 1);
                break;
            case 'q':
                this->_pc->move(-1, -1);
                break;
            case 'e':
                this->_pc->move(-1, 1);
                break;
            case 'z':
                this->_pc->move(1, -1);
                break;
            case 'c':
                this->_pc->move(1, 1);
                break;
            case 'Q':
                res = 0;
                break;
            default:
                break;
        }
    }
}

RougeLike::~RougeLike() {
    delete (this->_pc);
    this->cleanupFloors();
    delete (this->floors);
}

void RougeLike::cleanupFloors() {
    for (auto itr = this->floors->begin(); itr != floors->end(); ++itr) {
        delete (*itr);
    }
}
