//
// Created by sacha on 28-11-22.
//
#ifndef F202_CANVAS_H
#define F202_CANVAS_H

#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Box.H>
#include <memory>  // shared_ptr
#include <vector>

#include "Cell.h"
#include "Text.h"
#include "../Board.h"



class Canvas {
    std::shared_ptr<Board> board;

    Text textMenu{"Sacha Testaert", {250, 250}, 90, FL_BLACK};
    Text textGameOver{"Game Over", {250, 250}, 90, FL_BLACK};
    Text textYouWin{"You Win!", {250, 250}, 90, FL_BLACK};

public:
    Canvas(std::shared_ptr<Board> board);
    void drawTargets();
    void draw();
    void mouseMove(Point mouseLoc);
    void mouseClick(Point mouseLoc);
    void keyPressed(int keyCode);
};


#endif //F202_CANVAS_H
