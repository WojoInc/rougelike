//
// Created by wojoinc on 11/11/17.
//

#ifndef ROUGELIKE_FLOOR_H
#define ROUGELIKE_FLOOR_H


class Floor {

private:
    unsigned char _width, _height;
    unsigned char _order;

public:
    Floor(unsigned char width, unsigned char height) {
        this->_width = width;
        this->_height = height;
    }

    Floor(unsigned char order) {
        this->_height = this->_width = 255;
        this->_order = order;
    }

    static void generateFloors(std::vector<Floor *> *floors);

};


#endif //ROUGELIKE_FLOOR_H
