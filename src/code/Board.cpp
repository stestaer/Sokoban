//
// Created by sacha on 10-11-22.
//

#include "Board.h"

Board::Board(const std::string &level) {
    if(!level.empty())
        loadBoard(level);

}

Board::~Board() {}

void Board::updateBoard(const Point &base, const Point &movedTo){
    board[movedTo.y][movedTo.x] = board[base.y][base.x];
    board[base.y][base.x] = CORRIDOR;
}


bool Board::isEmpty(const Point &target_position){
    return board[target_position.y][target_position.x]==CORRIDOR;
}

bool Board::isCrate(const Point &position){
    return board[position.y][position.x]==CRATE;
}

bool Board::isMovable(const Point &position, const Point &direction){
    return ( 0 <= position.y+direction.y < h && 0 <= position.x+direction.x < w
        && isEmpty(Point{position.y+direction.y, position.x+direction.x}));
}

void Board::movePlayer(const Point &position, const Point &destination, const int &object){
    //if(isMovable(position, direction)) donc, ici c'est un test qu'il faudra faire dans la boucle de jeu
    if (object == PLAYER){
        player.x = position.x+destination.x;
        player.y = position.y+destination.y;
    }
    updateBoard(position, destination);
}

void Board::saveBoard(){}


void Board::loadBoard(const std::string &text_file){
    std::ifstream input_file(text_file);
    input_file >> h >> w;
    int tmp;
    for (int i = 0; i < h; i++){
        board.push_back(std::vector<int>());
        for (int j = 0; j < w; j++){
            input_file >> tmp;
            board[i].push_back(tmp);
        }
    }
    input_file.close();
}

void Board::printBoard(){
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}