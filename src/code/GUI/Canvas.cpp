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
    drawLevelInfos();
}


void Canvas::drawLevelInfos()
{
    std::string current_record;
    if (board->getRecord()==std::numeric_limits<int>::max())
    {
        current_record = "NA";
    }
    else
    {
        current_record = std::to_string(board->getRecord());
    }
    std::string steps_basis = "Steps : " + std::to_string(board->getSteps()) + "/" + current_record;
    Text steps = {steps_basis, {cell_width+cell_width/2, board->getWidth()*cell_width+cell_width/2}, 10, FL_BLACK};
    steps.draw();


}

void Canvas::mouseMove(Point mouseLoc)
{}