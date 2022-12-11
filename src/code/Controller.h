//
// Created by sacha on 11-12-22.
//

#ifndef F202_CONTROLLER_H
#define F202_CONTROLLER_H


class Controller {
    shared_ptr<Board> board; //Model

public:

    bool isEmpty(const Point &position); // is a position not occupied by an object


    bool isCrate(const Point &position);


    bool isMovable(const Point &position, const Point &direction); //Point direction contient {1,0}/{0,1}/{0,-1}/{-1,0}
    // Descendre / Avancer à droite / Avancer à gauche / Monter

    void movePlayer(const Point &position,const Point &destination, const int &object=PLAYER); // moves the player in the matrix


    void updateBoard(const Point &base, const Point &movedTo);

};


#endif //F202_CONTROLLER_H
