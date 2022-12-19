//
// Created by sacha on 11-12-22.
//
#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Box.H>
#include <iostream>

#include "./shared/Point.h"
#include "./shared/block_values.h"
#include <memory>
#include "Board.h"

#ifndef F202_CONTROLLER_H
#define F202_CONTROLLER_H


class Controller {
    std::shared_ptr<Board> board; //Model

public:

    Controller(std::shared_ptr<Board> board);

    bool processEvent(int event);

    void movePlayer(Point &direction);

    void moveObject(Point &direction, Point &destination);


};


#endif //F202_CONTROLLER_H
