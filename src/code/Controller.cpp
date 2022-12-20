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
        if (board->getCell({player_pos.y+direction.y, player_pos.x+direction.x}).getCellType() == Crate)
        {
            moveObject({board->getPlayer().y+direction.y, board->getPlayer().x+direction.x},
                       {player_pos.y+direction.y*2, player_pos.x+direction.x*2});
        }
        Cell& c1 = tmp[player_pos.y][player_pos.x];
        Cell& c2 = tmp[player_pos.y+direction.y][player_pos.x+direction.x];
        board->changeTypes(c1, c2);
        board->movePlayer(direction.x,direction.y);
        std::cout<<board->getPlayer()<<std::endl;
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
