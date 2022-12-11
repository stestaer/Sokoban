//
// Created by sacha on 28-11-22.
//

#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Box.H>

#include "Canvas.h"
#include "Cell.h"

void Canvas::initialize()
{

}

void Canvas::draw()
{
    for (auto &v: cells)
        for (auto &c: v) {
            c->draw();
        }
    // We need to check to see if we need to draw game over or you win
    if (bombExposed())
        textGameOver.draw();
    if (solved()) {
        textYouWin.draw();
    }
}