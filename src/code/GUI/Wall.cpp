//
// Created by sacha on 30/11/22.
//

#include "Wall.h"

Wall::Wall(Point center, int w, int h)
{
    Wall(Point center, int w, int h)
    : Cell(center, w, h), blocked{true}{};
}

void Wall::draw()
{
    //TODO specific drawing of a wall
    r.setFillColor(FL_BLACK);
    r.

}