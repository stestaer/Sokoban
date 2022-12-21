//
// Created by sacha on 11-12-22.
//
#include "Controller.h"


Controller::Controller(std::shared_ptr<Board> board) : board{board} {}

void Controller::moveObject(Point start, Point destination)
{
    if (board->getCell(destination).getCellType() != Crate &&
        !board->getCell(destination).isBlocked())
        board->changeTypes(board->getCell(start), board->getCell(destination));
    board->updateBlockedStatus();
    //TODO faire un c.setBlocked() si jamais la caisse est dans un coin
    //TODO faire une méthode d'actualisation de ce statut
    // (si deux caisses sont côtées à côtes de sorte à ce que l'une soit bloquée, une fois la bloquante bougée,
    //   celle bloquée pourrait redevenir non-bloquée)
}


void Controller::movePlayer(Point &direction)
{
    if(board->checkPlayerMove(direction))
    {
        std::vector<std::vector<Cell>>& tmp = board->getCells();
        Point player_pos = board->getPlayer();
        if (board->getCell(player_pos+direction).getCellType() == Crate)
        {
            moveObject({player_pos+direction},
                       {player_pos.y+direction.y*2, player_pos.x+direction.x*2});
        }
        Cell& c1 = board->getCell(player_pos);
        Cell& c2 = board->getCell(player_pos+direction);
        if (c2.getCellType() != Crate)
        {
            board->changeTypes(c1, c2);
            board->movePlayer(direction);
            board->addStep();
            std::cout<<board->getPlayer()<<std::endl;
        }

    }
}

bool Controller::processEvent(int event)
{
    switch (event) {
        case FL_KEYDOWN:
            switch (Fl::event_key()) {
                case 32: //board space bar
                    board->loadBoard();
                    board->resetSteps();
                    return true;
                case FL_Up: // 1 on keyboard
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
