//
// Created by sacha on 10-11-22.
//
#include <vector>
#include <string>

#include "../shared/block_values.h"
#include "../shared/directions.h"
#include "Point.h"

#ifndef F202_PROJET_BOARD_H
#define F202_PROJET_BOARD_H


class Board {
    int w;
    int h;
    std::vector<std::vector<int>> *board;
    std::vector<Point> targets;

    void loadBoard(std::string level); // loads a matrix from a .txt files

public:
    Board();

    bool isOccupied(const Point &position); // is a position occupied by an object

    bool isCrate(const Point &position);

    bool isMovableCrate(const Point &position, const Point &direction); //Point direction contient {1,0}/{0,1}/{0,-1}/{-1,0}
                                                                          // Descendre / Avancer à droite / Avancer à gauche / Monter                                  
    bool isPlayerMovable(const Point &position, const Point &direction);

    void movePlayer(const Point &destination); // moves the player in the matrix

    void saveBoard(); //nothing for now

};


#endif //F202_PROJET_BOARD_H
