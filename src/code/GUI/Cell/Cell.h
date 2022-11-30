//
// Created by sacha on 23-11-22.
//
// Cell class mainly took from Lab3

#ifndef F202_PROJET_CELL_H
#define F202_PROJET_CELL_H

#include "../../shared/Point.h"


class Cell {
    Rectangle r;
public:
    // Constructor
    Cell(Point center, int w, int h);

    // Methods that draw and handle events
    virtual void draw();

    void mouseMove(Point mouseLoc);

    void mouseClick(Point mouseLoc);

};


#endif //F202_PROJET_CELL_H
