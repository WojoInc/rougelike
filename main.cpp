#include <iostream>
#include "Graphics.h"
#include "game_objects/Player.h"
#include "dungeon/Dungeon.h"


void main_loop(Player *pc){
    bool ctl_mode = false; //false = look, true = control
    bool first_move = false;//used to make sure monsters dont move_abs until PC has made its first turn
    int ch = 0;
    while(ch != 'Q') {
        ch = getch();

        switch (ch) {
            case '7':
            case 'q':
                if (ctl_mode) {
                    first_move = true;
                    pc->move_rel(-1, -1);
                }
                break;
            case '8':
            case 'w':
                if (ctl_mode) {
                    first_move = true;
                    pc->move_rel(0, -1);
                } else {
                    //mv_view(ui, -1, 0);
                }
                break;
            case '9':
            case 'e':
                if (ctl_mode) {
                    first_move = true;
                    pc->move_rel(1, -1);
                }
                break;
            case '6':
            case 'd':
                if (ctl_mode) {
                    first_move = true;
                    pc->move_rel(1, 0);
                } else {
                    //mv_view(ui, 0, 1);
                }
                break;
            case '3':
            case 'c':
                if (ctl_mode) {
                    first_move = true;
                    pc->move_rel(1, 1);
                }
                break;
            case '2':
            case 's':
                if (ctl_mode) {
                    first_move = true;
                    pc->move_rel(0, 1);
                } else {
                    //mv_view(ui, 1, 0);
                }
                break;
            case '1':
            case 'z':
                if (ctl_mode) {
                    first_move = true;
                    pc->move_rel(-1, 1);
                }
                break;
            case '4':
            case 'a':
                if (ctl_mode) {
                    first_move = true;
                    pc->move_rel(-1, 0);
                } else {
                    //mv_view(ui, 0, -1);
                }
                break;
            case '5':
            case ' ':
                if (ctl_mode) {
                    first_move = true;
                    //ctl_mv_p(-1);
                }
                break;
            case '>':
                if (ctl_mode) {
                    first_move = true;
                    //ctl_mv_p(8);
                }
                break;
            case '<':
                if (ctl_mode) {
                    first_move = true;
                    //ctl_mv_p(9);
                }
                break;
            case 'L':
                //if in control ctl_mode, switch to look ctl_mode
                if (ctl_mode) ctl_mode = false;
                break;
            case 27:
                //If in look ctl_mode, switch to control ctl_mode and then refocus view to player
                if (!ctl_mode) ctl_mode = true;
                //view_focus_player(ui, pEvent->player->location->w_unit->y, pEvent->player->location->w_unit->x);
                break;
            default:
                break;
        }
    }
}

int main() {

    initscr();
    cbreak();
    noecho();
    keypad(stdscr,FALSE);
    curs_set(0);
    getch();
    Dungeon dungeon(105, 160, 15);
    Player *pc = new Player(&dungeon);
    int ch = 0;
    pc->move_abs(45, 45);
    main_loop(pc);
    endwin();

    return 0;
}

