//
// Created by sacha on 28-11-22.
//
#include <memory>  // shared_ptr
#include <vector>
#include "Text.h"

#ifndef F202_CANVAS_H
#define F202_CANVAS_H


class Canvas {
    std::shared_ptr<Board> board;

    Text textMenu{"Sacha Testaert", {250, 250}, 90, FL_BLACK};
    Text textGameOver{"Game Over", {250, 250}, 90, fl_rgb_color(255, 0, 255)};
    Text textYouWin{"You Win!", {250, 250}, 90, FL_GREEN};
    void initialize();

public:
    Canvas() {
        initialize();
    }
    void draw();
    void mouseMove(Point mouseLoc);
    void mouseClick(Point mouseLoc);
    void keyPressed(int keyCode);
};


#endif //F202_CANVAS_H
