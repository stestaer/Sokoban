//
// Created by sacha on 23-11-22.
//
// Cell class mainly took from Lab3

#ifndef F202_PROJET_CELL_H
#define F202_PROJET_CELL_H

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
    // Constructor
    Cell(Point center, int w, int h, CellType cell_type);

    ~Cell() = default;

    bool isBlocked(){return blocked;};

    void setBlocked(){blocked = true;};

    void setUnblocked(){blocked = false;};

    CellType getCellType();
    void setCellType(CellType new_type);
    // Methods that draw and handle events

    void corridorDraw();

    void crateDraw();

    void targetDraw(); //TODO faire une méthode dans canvas qui get les taregets du board et les dessine toutes AVANT LES CRATES SOIT AVANT LE SWITCH

    //void wallDraw(); //default case in draw() switch;

    void playerDraw();

    void draw();

    void drawCrateOnTarget();

    void mouseMove(Point mouseLoc);

    void mouseClick(Point mouseLoc);

};


#endif //F202_PROJET_CELL_H
