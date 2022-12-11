//
// Created by sacha on 11-12-22.
//

#include "Controller.h"

void Controller::updateBoard(const Point &base, const Point &movedTo)
{
    board[movedTo.y][movedTo.x] = board[base.y][base.x];
    board[base.y][base.x] = CORRIDOR;
}

bool Controller::isEmpty(const Point &target_position)
{
    return board[target_position.y][target_position.x]==CORRIDOR;
}

bool Controller::isCrate(const Point &position)
{
    return board[position.y][position.x]==CRATE;
}

bool Controller::isMovable(const Point &position, const Point &direction)
{
    return ( 0 <= position.y+direction.y < h && 0 <= position.x+direction.x < w
             && isEmpty(Point{position.y+direction.y, position.x+direction.x}));
}

void Controller::movePlayer(const Point &position, const Point &destination, const int &object)
{
    //if(isMovable(position, direction)) donc, ici c'est un test qu'il faudra faire dans la boucle de jeu
    if (object == PLAYER)
    {
        player.x = position.x+destination.x;
        player.y = position.y+destination.y;
    }
    updateBoard(position, destination);
}