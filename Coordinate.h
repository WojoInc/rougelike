//
// Created by wojoinc on 4/21/18.
//

#ifndef ROUGELIKE_COORDINATE_H
#define ROUGELIKE_COORDINATE_H


class Coordinate {
private:
    unsigned int _x, _y;
public:
    Coordinate(unsigned int _x, unsigned int _y);

    unsigned int get_x() const;

    void set_x(unsigned int _x);

    unsigned int get_y() const;

    void set_y(unsigned int _y);
};


#endif //ROUGELIKE_COORDINATE_H
