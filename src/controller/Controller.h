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
#include <iostream>
#include <memory>

#include "../model/Board.h"
#include "../shared/Point.h"
#include "../shared/directions.h"
#include "../shared/block_values.h"



class Controller {
    std::shared_ptr<Board> board;
    bool do_resize = false;

public:

    explicit Controller(std::shared_ptr<Board> board);

    void changeLevel(int desired_level=None);

    bool processEvent(int event);

    bool mustResize(){ return do_resize; };

    void movePlayer(Point &direction);

    void moveObject(Point start, Point destination);

};


#endif //F202_CONTROLLER_H
