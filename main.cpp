
#include "main.h"
#include "RougeLike.h"

static void setup_window() {
    initscr();
    clear();
    noecho();
    cbreak();
    keypad(stdscr, false);
    curs_set(0);
}

static void cleanup_window() {
    endwin();
}

int main(int argc, char *argv[]) {
    setup_window();
    RougeLike *rg = new RougeLike;
    rg->main_loop();
    cleanup_window();

}