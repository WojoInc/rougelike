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
                mvaddch(this->p_y, this->p_x, ' ');
                mvaddch(--this->p_y, this->p_x, '@');
                break;
            case 's':
                mvaddch(this->p_y, this->p_x, ' ');
                mvaddch(++this->p_y, this->p_x, '@');
                break;
            case 'a':
                mvaddch(this->p_y, this->p_x, ' ');
                mvaddch(this->p_y, --this->p_x, '@');
                break;
            case 'd':
                mvaddch(this->p_y, this->p_x, ' ');
                mvaddch(this->p_y, ++this->p_x, '@');
                break;
            case 'Q':
                res = 0;
                break;
            default:
                break;
        }
    }
}
