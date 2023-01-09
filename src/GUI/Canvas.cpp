//
// Created by sacha on 28-11-22.
//
#include "Canvas.h"

Canvas::Canvas(std::shared_ptr<Board> board): board{board}{}

void Canvas::drawWaitingScreen(int x, int y)
{
    Text textMenu{"Sacha Testaert", {y/2, x/2}, 30, FL_BLACK};
    textMenu.draw();
}

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
    Text current_level = {"Level "+std::to_string(board->getLevel()+1), {cell_width-cell_width/2 - int(cell_width*0.2), board->getWidth()*cell_width/2}, int(floor(cell_width*55/100)), FL_BLACK};
    std::string current_record;
    current_level.draw();
    if (board->getRecord()==std::numeric_limits<int>::max())
    {
        current_record = "NA";
    }
    else
    {
        current_record = std::to_string(board->getRecord());
    }
    std::string steps_basis = "" + std::to_string(board->getSteps()) + "/" + current_record;
    Text steps = {steps_basis, {cell_width+cell_width/2, board->getWidth()*cell_width+cell_width}, int(floor(cell_width*30/100)), FL_BLACK};
    steps.draw();


}
