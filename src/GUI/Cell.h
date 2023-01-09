//
// Created by sacha on 23-11-22.
//
// Cell class mainly took from Lab3

#ifndef F202_CELL_H
#define F202_CELL_H

#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Box.H>

#include "../shared/Point.h"
#include "../shared/block_values.h"
#include "Rectangle.h"


class Cell {
    Rectangle r;
    CellType cell_type;
    bool blocked=false;
public:

    Cell(Point center, int w, int h, CellType cell_type);

    ~Cell() = default;

    bool isBlocked(){return blocked;};

    void setBlocked(){blocked = true;};

    void setUnblocked(){blocked = false;};

    /**
     * cell_type from enum CellType in ../shared/block_values.h
     * @return cell_type
     */
    CellType getCellType();

    void setCellType(CellType new_type);

    void corridorDraw();

    void crateDraw();

    void targetDraw();

    void playerDraw();

    /**
     * Calls specific "drawMethod" method for each cell
     * depending of its type
     */
    void draw();

    void drawCrateOnTarget();

    void mouseMove(Point mouseLoc);

    void mouseClick(Point mouseLoc);

};


#endif //F202_CELL_H
