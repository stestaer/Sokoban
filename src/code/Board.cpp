//
// Created by sacha on 10-11-22.
//

#include "Board.h"



bool Board::isOccupied(const Point &target_position){
    return board[target_position.y][target_position.x]==CORRIDOR;
}

bool Board::isCrate(const Point &position){
    return board[position.y][position.x]==CRATE;
}

bool Board::isMovableCrate(const Point &position, const Point &direction){
    if ( 0 <= position.y+direction.y < this->h
        && 0 <= position.x+direction.x < this->w
        && board[position.y+direction.y][position.x+direction.x]==CORRIDOR)
    {return true;}
    else 
        return false; 
}

bool Board::isPlayerMovable(const Point &position)