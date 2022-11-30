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
#include "Cell/Cell.h"

#ifndef F202_PROJET_BOARD_H
#define F202_PROJET_BOARD_H


class Board {
    int w;
    int h;
    std::vector<std::vector<Cell>> cells;
    std::vector<Cell *> targets(int x, int y);
    Point player;


public:
    Board(const std::string &level="");

    ~Board();

    bool isEmpty(const Point &position); // is a position occupied by an object

    bool isCrate(const Point &position);

    bool isMovable(const Point &position, const Point &direction); //Point direction contient {1,0}/{0,1}/{0,-1}/{-1,0}
                                                                          // Descendre / Avancer à droite / Avancer à gauche / Monter
    /**
    *
    * @param position
    * @param destination
    * @param direction
    *
    * @brief method called only after a "isMovable" in game Loop;
    */
    void movePlayer(const Point &position,const Point &destination, const int &object=PLAYER); // moves the player in the matrix

    /**
    *
    * @param base
    * @param movedTo
    * @brief change appropriate values in board
    */
    void updateBoard(const Point &base, const Point &movedTo);

    void saveBoard(); //nothing for now

    //void loadBoard(std::string &level); // loads a matrix from a .txt files

    const std::vector<std::vector<int>>& getBoard();

    void loadBoard(const std::string &text_file);

    void printBoard(void);
};


#endif //F202_PROJET_BOARD_H
