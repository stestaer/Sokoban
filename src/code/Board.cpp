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