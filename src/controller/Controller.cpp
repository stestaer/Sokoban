//
// Created by sacha on 11-12-22.
//
#include "Controller.h"


Controller::Controller(std::shared_ptr<Board> board) : board{board} {}

void Controller::changeLevel(int desired_level)
{
        board->loadBoard(desired_level);
}


void Controller::moveObject(Point start, Point destination)
{
    if (board->getCell(destination).getCellType() != Crate &&
        !board->getCell(destination).isBlocked())
        board->changeTypes(board->getCell(start), board->getCell(destination));
    board->updateBlockedStatus();
}


void Controller::movePlayer(Point &direction)
{
    if(board->checkPlayerMove(direction))
    {
        std::vector<std::vector<Cell>>& tmp = board->getCells();
        Point player_pos = board->getPlayer();
        if (board->getCell(player_pos+direction).getCellType() == Crate)
        {
            moveObject(player_pos+direction,
                       player_pos+direction+direction);
        }
        Cell& c1 = board->getCell(player_pos);
        Cell& c2 = board->getCell(player_pos+direction);
        if (c2.getCellType() != Crate)
        {
            board->changeTypes(c1, c2);
            board->movePlayer(direction);
            board->addStep();
        }

    }
}

bool Controller::processEvent(int event)
{
    switch (event) {
        case FL_KEYDOWN:
            switch (Fl::event_key()) {
                case 32: //space bar resets current level
                    board->resetSteps();
                    board->loadBoard(board->getLevel());
                    return true;
                case FL_Up:
                    movePlayer(UP);
                    return true;
                case FL_Down:
                    movePlayer(DOWN);
                    return true;
                case FL_Left:
                    movePlayer(LEFT);
                    return true;
                case FL_Right:
                    movePlayer(RIGHT);
                    return true;
                case 'r':
                    board->resetRecord();
                    return true;
                case 'b':
                    changeLevel(board->getLevel()-1);
                    do_resize = true;
                    return true;
                case 'n':
                    changeLevel(board->getLevel()+1);
                    do_resize = true;
                    return true;
                case 'l':
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
