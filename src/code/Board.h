//
// Created by sacha on 10-11-22.
//
#ifndef F202_BOARD_H
#define F202_BOARD_H

#include <vector>
#include <string>
#include <iostream>
#include <stdio.h>
#include <fstream>

#include "GUI/Cell.h"
#include "shared/levels.h"
#include "shared/Point.h"
#include "shared/directions.h"
#include "shared/block_values.h"



class Board {
    int rows;
    int cols;
    std::string level;
    std::vector<std::vector<Cell>> cells;
    std::vector<Point> crates;
    std::vector<Point> targets;
    Point player;
    GameState gameState = Playing;


public:
    Board(const std::string &level="../levels/level_1.txt");

    ~Board();

    int getHeight();

    int getWidth();

    GameState getState(){return gameState;};

    Point getPlayer();

    Cell& getCell(Point cell);

    void movePlayer(int x, int y){player.x += x;player.y += y;};

    void changeTypes(Cell &c1, Cell &c2);

    bool solved();

    bool isBlocked(Point& position);

    bool allBlocked();

    bool updateBlockedStatus();

    bool checkPlayerMove(Point &direction);

    std::vector<std::vector<Cell>>& getCells();

    std::vector<Point>& getTargets();

    void loadBoard(const std::string &text_file);

    void loadBoard();

    void printBoard(void);
};


#endif //F202_BOARD_H
