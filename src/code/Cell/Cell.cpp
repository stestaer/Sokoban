//
// Created by sacha on 23-11-22.
//

#include "Cell.h"


Cell::Cell(Point center, int w, int h):
        r(center, w, h, FL_BLACK, FL_WHITE) {}

virtual void Cell::draw()
{
    r.draw();
}