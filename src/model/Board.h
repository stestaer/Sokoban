//
// Created by sacha on 10-11-22.
//
#ifndef F202_BOARD_H
#define F202_BOARD_H

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <vector>
#include <limits>

#include "../levels/levels.h"
#include "../GUI/Cell.h"
#include "../shared/Point.h"
#include "../shared/directions.h"
#include "../shared/block_values.h"



class Board {
    int rows;
    int cols;
    int stepsRecord = std::numeric_limits<int>::max();
    int currentSteps;
    std::string level;
    int lvl = 0;
    std::vector<std::vector<Cell>> cells;
    std::vector<Point> crates;
    std::vector<Point> targets;
    Point player;
    GameState gameState;


public:
    Board(const std::string &level="src/levels/level_1.txt");

    ~Board();

    int getLevel(){ return lvl; };

    int getHeight();

    int getWidth();

    int getRecord(){ return stepsRecord; };

    int getSteps(){ return currentSteps; };

    void resetSteps() { currentSteps = 0; };

    void resetRecord();

    void addStep(){ currentSteps++; };

    void saveSteps();

    GameState getState(){ return gameState; };

    void changeState(GameState newState){ gameState=newState; };

    Point getPlayer();

    Cell& getCell(Point cell);

    void movePlayer(Point &direction){player.x += direction.x;player.y += direction.y;};

    void changeTypes(Cell &c1, Cell &c2);

    /**
     * Checks if targets are all covered by a crate
     * changes gameState to Won value
     * @return
     */
    bool solved();

    /**
     * States if a crate is blocked depending of its neighbors cells
     * and sets it to blocked or not
     * @param position
     * @return
     */
    bool isBlocked(Point& position);

    /**
     * Calls isBlocked() on every crate
     * @return
     */
    bool allBlocked();

    /**
     * Checks if the game is Lost or Won
     */
    void updateBlockedStatus();

    bool checkPlayerMove(Point &direction);

    std::vector<std::vector<Cell>>& getCells();

    std::vector<Point>& getTargets();

    /**
     * Loads a level from a specific text file
     * @param text_file
     */
    void loadBoard(const std::string &text_file);

    /**
     * Overloading of loadBoard(const std::string &text_file)
     * Loads a level from a specific text file with int value,
     * The loaded board is the current one
     * @param desired_level
     */
    void loadBoard(int desired_level = None );

    /**
     * Debug purpose
     * prints the text file in the stdout
     */
    void printBoard(void);
};


#endif //F202_BOARD_H
