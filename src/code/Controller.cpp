//
// Created by sacha on 11-12-22.
//

#include "Controller.h"


Controller::Controller(std::shared_ptr<Board> board) : board{board} {}

bool Controller::processEvent(int event)
{
    switch (event) {
        case FL_KEYDOWN:
            break;
        case FL_PUSH:
            switch (Fl::event_key()) {
                case ' ': //Reset board
                    return true;
                case 'q':
                    exit(0);
                default:
                    return false;
            }
        default:
            return false;
    }
    return false;
}
