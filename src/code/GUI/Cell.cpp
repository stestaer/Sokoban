//
// Created by sacha on 23-11-22.
//

#include "Cell.h"


Cell::Cell(Point center, int w, int h, CellType cell_type):
        r(center, w, h, FL_WHITE, FL_WHITE), cell_type{cell_type} {}


void Cell::draw()
{
    r.draw();
}

CellType Cell::getCellType(){ return cell_type; }

void Cell::setCellType(CellType new_type){ cell_type = new_type; }

void Cell::mouseMove(Point mouseLoc)
{
    if (r.contains(mouseLoc)) {
        r.setFrameColor(FL_BLACK);
    } else {
        r.setFrameColor(r.getFillColor());
    }
}

void Cell::mouseClick(Point mouseLoc) {

}