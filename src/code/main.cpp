//
// Created by sacha on 11-11-22.
//

#include "Board.h"

int main(){
    Board board{"../levels/level_1.txt"}; // add a path to load a matrix
    board.printBoard();
    return 0;
}