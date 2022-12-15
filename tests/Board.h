//
// Created by sacha on 09-12-22.
//

#ifndef F202_BOARD_H
#define F202_BOARD_H


class Board {
    std::vector<std::vector<Cell>> cells;
    Point player;

public:
    Point getPlayerPosition();
    void setPlayerPosition();

};


#endif //F202_BOARD_H
