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
    stepsCounter.draw();
    // We need to check to see if we need to draw game over or you win
    //TODO une méthode de controller pour cet affichage avec le gameState dans le bord en private
    // qui indique si le joueur est encore autorisé à bouger sur le plateau(non quand jeu est win ou perdu)
    //  car trop de calculs par seconde avec updateBlockedStatus()
    //if (board->updateBlockedStatus())
    //    textGameOver.draw();
    //if (board->solved()) {
    //    textYouWin.draw();
    //}
}

void Canvas::draw(GameState current_status)
{
    switch (current_status) {
        case Won:
            textYouWin.draw();
            break;
        case Lost:
            textGameOver.draw();
            break;
        default:
            break;

    }
}

void Canvas::mouseMove(Point mouseLoc)
{}