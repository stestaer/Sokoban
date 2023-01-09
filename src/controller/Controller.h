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

#include "../model/Board.h"
#include "../shared/Point.h"
#include "../shared/directions.h"
#include "../shared/block_values.h"



class Controller {
    std::shared_ptr<Board> board;
    bool do_resize = false;

public:

    Controller(std::shared_ptr<Board> board);

    /**
     * change to a particular level
     * @param desired_level
     */
    void changeLevel(int desired_level=None);

    /**
     * process any event that occurs whether it is a mouse movement or a pressed key
     * @param event
     * @return boolean
     */
    bool processEvent(int event);

    /**
     * used in MainWindow Object to know if it is needed to resize the application frame
     * @return do_resize
     */
    bool mustResize(){ return do_resize; };

    /**
     * Move the player in a certain with a determined step length (1 cell) if the move is legal (in boundaries)
     * and manages the movement of objects on the player's way
     * @param direction in {RIGHT, LEFT, UP, DOWN}
     */
    void movePlayer(Point &direction);

    /**
     * Move crates if player pushes them, it also update the gameStatus by calling updateBlockedStatus()
     * @param start
     * @param destination
     */
    void moveObject(Point start, Point destination);

};


#endif //F202_CONTROLLER_H
