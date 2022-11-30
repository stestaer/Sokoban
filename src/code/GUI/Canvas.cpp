//
// Created by sacha on 28-11-22.
//

#include "Canvas.h"
#include "Cell/Cell.h"

void Canvas::initialize()
{

}

bool Canvas::solved()
{

}

void Canvas::draw()
{
    for (auto &v: cells)
        for (auto &c: v) {
// Replace draw here if you want to see what it should look like after task 2/3
//            c.drawTaskTwo();
//            c.drawTaskThree();
            c.draw();
        }
    // We need to check to see if we need to draw game over or you win
    if (bombExposed())
        textGameOver.draw();
    if (solved()) {
        textYouWin.draw();
    }
}