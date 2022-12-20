//
// Created by sacha on 11-12-22.
//
#ifndef F202_CONTROLLER_H
#define F202_CONTROLLER_H

#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Box.H>
#include <iostream>
#include <iostream>
#include <memory>

#include "Board.h"
#include "./shared/Point.h"
#include "./shared/directions.h"
#include "./shared/block_values.h"



class Controller {
    std::shared_ptr<Board> board; //Model

public:

    Controller(std::shared_ptr<Board> board);

    bool processEvent(int event);

    void movePlayer(Point &direction);

    void moveObject(Point start, Point destination);

    void move();
    //TODO faire une fonction appelée à chaque déplacement uqi lancera
    // la procédure moveObject si jamais le joueur se trouve à bouger une caisse, cette méthode devra update le
    //  statut de la caisse et checker si toutes les crates sont bloqquées


};


#endif //F202_CONTROLLER_H
