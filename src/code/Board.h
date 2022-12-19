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

#ifndef F202_PROJET_BOARD_H
#define F202_PROJET_BOARD_H


class Board {
    int w;
    int h;
    std::vector<std::vector<Cell>> cells;
    std::vector<Point> targets;
    Point player;


public:
    Board(const std::string &level="../levels/level_1.txt");

    ~Board();

    int getHeight();

    int getWidth();

    Point getPlayer();

    void changeTypes(Cell &c1, Cell &c2);

    bool solved();

    bool allBlocked();

    std::vector<std::vector<Cell>>& getCells();

    std::vector<Point>& getTargets();

    void loadBoard(const std::string &text_file);

    void printBoard(void);
};


#endif //F202_PROJET_BOARD_H
