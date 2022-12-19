//
// Created by sacha on 23-11-22.
//

#include "Cell.h"


Cell::Cell(Point center, int w, int h, CellType cell_type):
        r(center, w, h, FL_WHITE, FL_WHITE), cell_type{cell_type} {
    if(cell_type == Wall){
        r.setColor(wall_color);
    }
}

void Cell::corridorDraw()
{
    r.setColor(corridor_color);
    r.draw();
}

void Cell::crateDraw()
{
    r.setFrameColor(FL_BLACK);
    r.setFillColor(crate_Color);
    r.draw();
}

void Cell::targetDraw()
{
    this->corridorDraw();
    //TODO faire un dessin de cible
    // (2cercles supperposés de couleurs différentes)
    Point center = r.getCenter();
    fl_color(FL_BLACK);
    fl_begin_polygon();
    fl_circle(center.x, center.y, player_radius/3+2);
    fl_end_polygon();
    fl_color(target_color);
    fl_begin_polygon();
    fl_circle(center.x, center.y, player_radius/3);
    fl_end_polygon();
}

//void Cell::wallDraw()
//{
//    r.draw();
//}

void Cell::playerDraw()
{
    r.setColor(corridor_color);
    r.draw();
    Point center = r.getCenter();
    fl_color(player_color);
    fl_begin_polygon();
    fl_circle(center.x, center.y, player_radius);
    fl_end_polygon();
}


void Cell::draw()
{
    switch (cell_type) {
        case Corridor:
            corridorDraw();
            break;
        case Crate:
            crateDraw();
            break;
        case Player:
            playerDraw();
            break;
        default:
            r.draw();
            break;
    }

}

void Cell::drawCrateOnTarget()
{
    r.setFrameColor(FL_BLACK);
    r.setFillColor(crate_on_target_color);
    r.draw();
}

CellType Cell::getCellType(){ return cell_type; }

void Cell::setCellType(CellType new_type){ cell_type = new_type; }

void Cell::mouseMove(Point mouseLoc)
{
    if (r.contains(mouseLoc)) {
        r.setFrameColor(FL_BLACK);
    } else {
        r.setFrameColor(r.getFillColor());
    }
}

void Cell::mouseClick(Point mouseLoc) {

}