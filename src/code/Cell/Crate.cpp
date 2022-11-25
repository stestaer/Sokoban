//
// Created by sacha on 25-11-22.
//

#include "Crate.h"


Crate::Crate(Point center, int w, int h)
{
    Crate(Point center, int w, int h)
        : Cell(center, w, h), blocked{false}{};
}

void Crate::draw() override
{
    //TODO specific drawing of a crate
}