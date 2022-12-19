//
// Created by sacha on 11-12-22.
//
#include "./shared/directions.h"
#include "Controller.h"


Controller::Controller(std::shared_ptr<Board> board) : board{board} {}

void Controller::movePlayer(Point &direction)
{
    if(board->checkMove(direction)){
        Point player_pos = board->getPlayer();
        std::vector<std::vector<Cell>>& tmp = board->getCells();
        Cell& c1 = tmp[player_pos.y][player_pos.x]; //TODO fix le swap
        Cell& c2 = tmp[player_pos.y+direction.y][player_pos.x+direction.x];
        board->changeTypes(c1, c2);
        board->movePlayer(direction.x,direction.y);
    }
}

bool Controller::processEvent(int event)
{
    switch (event) {
        case FL_KEYDOWN:
            switch (Fl::event_key()) {
                case 32: //board space bar
                    board->loadBoard();
                    return true;
                case FL_Up: // 1 on keyboard

                    return true;
                case FL_Down:

                    return true;
                case FL_Left:
                    movePlayer(LEFT);
                    return true;
                case FL_Right:

                    return true;
                case 'h':
                    break;
                case 'l': // l
                    exit(0);
                default:
                    return false;
            }
            break;
        case FL_PUSH:
            switch (Fl::event_key()) {

                default:
                    return false;
            }
        default:
            return false;
    }
    return false;
}
