//
// Created by sacha on 11-12-22.
//

#include "Controller.h"


Controller::Controller(std::shared_ptr<Board> board) : board{board} {}

bool Controller::processEvent(int event)
{
    return event;
}
