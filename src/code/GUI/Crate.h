//
// Created by sacha on 25-11-22.
//

#ifndef F202_CRATE_H
#define F202_CRATE_H

#include "../shared/Point.h"
#include "Cell.h"


class Crate : public Cell{
    bool blocked;
    int w;
    int h;

public:

    Crate(Point center, int w, int h, bool blocked);

    void draw() override;

};


#endif //F202_CRATE_H
