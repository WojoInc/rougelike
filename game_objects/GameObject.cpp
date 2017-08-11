//
// Created by root on 8/10/17.
//

#include "GameObject.h"


void GameObject::draw() {
    for(unsigned int i = 0; i < d_height; i++){
            std::string toWrite = ((std::string)sprite).substr((d_width*i),d_width);
            mvaddstr(d_y+i,d_x,toWrite.c_str());
    }

}

void GameObject::erase() {
    for(unsigned int i = 0; i < d_height; i++){
        /*std::string toWrite = ((std::string)sprite).substr((d_width*i),d_width);
        mvaddstr(d_y+i,d_x,toWrite.c_str());*/
        mvaddch(d_y+i, d_x, dungeon);
    }

}
