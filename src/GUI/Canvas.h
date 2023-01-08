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
#include <string>
#include <limits>
#include <cmath>

#include "Cell.h"
#include "Text.h"
#include "../shared/block_values.h"
#include "../shared/window_values.h"
#include "../model/Board.h"



class Canvas {
    std::shared_ptr<Board> board;

public:
    Canvas(std::shared_ptr<Board> board);

    void drawWaitingScreen(int x, int y);

    void drawTargets();

    void draw();

    void drawLevelInfos();

    void mouseMove(Point mouseLoc);

    void mouseClick(Point mouseLoc);

    void keyPressed(int keyCode);
};


#endif //F202_CANVAS_H
