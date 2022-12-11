//
// Created by sacha on 10-11-22.
//
#include <vector>
#include <string>
#include <iostream>
#include <stdio.h>
#include <fstream>

#include "shared/block_values.h"
#include "shared/directions.h"
#include "shared/Point.h"
#include "GUI/Cell.h"
#include "GUI/Crate.h"
#include "GUI/Wall.h"

#ifndef F202_PROJET_BOARD_H
#define F202_PROJET_BOARD_H


class Board {
    int w;
    int h;
    std::vector<std::vector<Cell>> cells;
    std::vector<Cell *> targets;
    Point player;


public:
    Board(const std::string &level="");


    ~Board();


    bool solved();

    void saveBoard(); //nothing for now


    //void loadBoard(std::string &level); // loads a matrix from a .txt files


    const std::vector<std::vector<int>>& getBoard();

    void loadBoard(const std::string &text_file);

    void printBoard(void);
};


#endif //F202_PROJET_BOARD_H
