//
// Created by sacha on 28-11-22.
//
#ifndef F202_MAINWINDOW_H
#define F202_MAINWINDOW_H

#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Box.H>

#include <string>
#include <unistd.h>
#include "shared/window_values.h"
#include "../levels/levels.h"
#include "GUI/Canvas.h"
#include "Controller.h"
#include "Board.h"


class MainWindow : public Fl_Window {
    std::shared_ptr<Board> board;
    Canvas canvas;
    Controller controller;
    int waitingScreen_frames = 60;

public:

    MainWindow() : Fl_Window(400, 400, windowWidth, windowHeight, "Sokoban"),
        board{std::make_shared<Board>()},
                   canvas(board),
                   controller(board){
        Fl::add_timeout(1.0/refreshPerSecond, Timer_CB, this);
        resizable(this);
        Fl_Window::resize(Fl_Window::x_root(), Fl_Window::y_root(), board->getWidth()*cell_width+2*cell_width, board->getHeight()*cell_width+cell_width);
    }

    void draw() override
    {
        Fl_Window::draw();
        if (waitingScreen_frames != 0)
        {
            canvas.drawWaitingScreen(Fl_Window::x_root(), Fl_Window::y_root());
            waitingScreen_frames--;
        }
        else
        {
            GameState current_status = board->getState();
            if (current_status == Won)
            {
                if (board->getLevel() < LEVELS.size()-1)
                {
                    board->loadBoard(board->getLevel()+1);
                }
                else if (board->getLevel() == LEVELS.size()-1)
                {
                    board->loadBoard();
                }
                Fl_Window::resize(Fl_Window::x_root(), Fl_Window::y_root(), board->getWidth()*cell_width+2*cell_width, board->getHeight()*cell_width+cell_width);

            }
            if (current_status == Lost)
                board->loadBoard(board->getLevel());
            if (controller.mustResize())
                Fl_Window::resize(Fl_Window::x_root(), Fl_Window::y_root(), board->getWidth()*cell_width+2*cell_width, board->getHeight()*cell_width+cell_width);

            canvas.draw();
        }
    }

    int handle(int event) override
    {
        return controller.processEvent(event);
    }

    static void Timer_CB(void *userdata)
    {
        MainWindow *o = static_cast<MainWindow*>(userdata);
        o->redraw();
        Fl::repeat_timeout(1.0/refreshPerSecond, Timer_CB, userdata);
    }
};

#endif //F202_MAINWINDOW_H
