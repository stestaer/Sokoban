//
// Created by sacha on 30/11/22.
//

#ifndef PROJET_WALL_H
#define PROJET_WALL_H

#include "../shared/Point.h"
#include "Cell.h"

class Wall: public Cell {
    bool blocked;

public:

    Wall(Point center, int w, int h);

    void draw() override;
};


#endif //PROJET_WALL_H
