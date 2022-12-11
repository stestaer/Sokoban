//
// Created by sacha on 10-11-22.
//

#include "Board.h"

Board::Board(const std::string &level)
{
    if(!level.empty())
        loadBoard(level);
}

Board::~Board() {}

void Board::saveBoard(){}


void Board::loadBoard(const std::string &text_file)
{
    std::ifstream input_file(text_file);
    input_file >> h >> w;
    int tmp;
    for (int i = 0; i < h; i++)
    {
        board.push_back(std::vector<Cell>());
        for (int j = 0; j < w; j++)
        {
            input_file >> tmp;
            board[i].push_back(tmp);
        }
    }
    input_file.close();
}

void Board::printBoard(void)
{
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}