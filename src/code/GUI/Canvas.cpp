//
// Created by sacha on 28-11-22.
//
#include "Canvas.h"

Canvas::Canvas(std::shared_ptr<Board> board): board{board}{}

void Canvas::drawTargets()
{
    std::vector<std::vector<Cell>>& b = board->getCells();
    for(auto &p: board->getTargets())
    {
        if(b[p.y][p.x].getCellType() == Crate)
        {
            b[p.y][p.x].drawCrateOnTarget();
        }
        else if(b[p.y][p.x].getCellType() != Player)
        {
            b[p.y][p.x].targetDraw();
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
    //TODO peut etre faire une méthode de controller pour cet affichage avec un booleen dans le bord en private
    // qui indiquerait si le joueur serait encore autorisé à bouger sur le plateau(non quand jeu est win ou perdu)
    if (board->allBlocked())
        textGameOver.draw();
    if (board->solved()) {
        textYouWin.draw();
    }
}

void Canvas::mouseMove(Point mouseLoc)
{}