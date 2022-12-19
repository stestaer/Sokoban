//
// Created by sacha on 28-11-22.
//
#include "Canvas.h"

Canvas::Canvas(std::shared_ptr<Board> board): board{board}{}

void Canvas::drawTargets()
{
    std::vector<std::vector<Cell>>& tmp = board->getCells();
    for(auto &p: board->getTargets())
    {
        if(tmp[p.y][p.x].getCellType() == Crate)
        {
            tmp[p.y][p.x].drawCrateOnTarget();
        }
        else
        {
            tmp[p.y][p.x].targetDraw();
        }

    }
}

void Canvas::draw()
{
    for (auto &v: board->getCells())
        for (auto &c: v) {
            c.draw();
        }
    drawTargets();
    // We need to check to see if we need to draw game over or you win
    if (board->allBlocked())
        textGameOver.draw();
    if (board->solved()) {
        textYouWin.draw();
    }
}

void Canvas::mouseMove(Point mouseLoc)
{}