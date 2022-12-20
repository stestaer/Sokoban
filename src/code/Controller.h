//
// Created by sacha on 11-12-22.
//
#ifndef F202_CONTROLLER_H
#define F202_CONTROLLER_H

#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Box.H>
#include <iostream>

#include "./shared/Point.h"
#include "./shared/block_values.h"
#include <iostream>
#include <memory>
#include "Board.h"



class Controller {
    std::shared_ptr<Board> board; //Model

public:

    Controller(std::shared_ptr<Board> board);

    bool processEvent(int event);

    void movePlayer(Point &direction);

    void moveObject(Point start, Point destination);


};


#endif //F202_CONTROLLER_H
