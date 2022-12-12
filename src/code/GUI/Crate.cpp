//
// Created by sacha on 25-11-22.
//

#include "Crate.h"


Crate::Crate(Point center, int w, int h, bool blocked)
{
    Crate(Point center, int w, int h, bool blocked)
        : Cell(center, w, h), blocked{false}{}
}

void Crate::draw()
{
    //TODO specific drawing of a crate
}