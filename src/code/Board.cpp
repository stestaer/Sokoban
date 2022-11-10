//
// Created by sacha on 10-11-22.
//

#include "Board.h"

Board::Board() {}

Board::~Board() {}

void Board::updateBoard(const Point &base, const Point &movedTo){
    *board[movedTo.y][movedTo.x] = *board[base.y][base.x];
    *board[base.y][base.x] == CORRIDOR;
}


bool Board::isEmpty(const Point &target_position){
    return board[target_position.y][target_position.x]==CORRIDOR;
}

bool Board::isCrate(const Point &position){
    return board[position.y][position.x]==CRATE;
}

bool Board::isMovable(const Point &position, const Point &direction){
    return ( 0 <= position.y+direction.y < this->h && 0 <= position.x+direction.x < this->w
        && isEmpty(Point{position.y+direction.y, position.x+direction.x}))
}

void Board::movePlayer(const Point &position, const Point &destination){
    //if(isMovable(position, direction)) donc, ici c'est un test qu'il faudra faire dans la boucle de jeu
    *player.x = position.x+destination.x;
    *player.y = position.y+destination.y;
    updateBoard(position, destination);

}

void Board::saveBoard(){}

void Board::loadBoard(){}