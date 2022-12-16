//
// Created by sacha on 28-11-22.
//
#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Box.H>

#include "shared/window_values.h"
#include "GUI/Canvas.h"
#include "Controller.h"

#ifndef F202_MAINWINDOW_H
#define F202_MAINWINDOW_H

class MainWindow : public Fl_Window {
    std::shared_ptr<Board> board;
    Canvas canvas;
    Controller controller;

public:
    MainWindow() : Fl_Window(500, 500, windowWidth, windowHeight, "Sokoban"),
        board{std::make_shared<Board>()},
                   canvas(board),
                   controller(board){
        Fl::add_timeout(1.0/refreshPerSecond, Timer_CB, this);
        resizable(this);
    }
    void draw() override
    {
        Fl_Window::draw();
        canvas.draw();
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
