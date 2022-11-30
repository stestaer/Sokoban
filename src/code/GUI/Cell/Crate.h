//
// Created by sacha on 25-11-22.
//

#ifndef F202_CRATE_H
#define F202_CRATE_H

#include "Cell.h"


class Crate : public Cell{
    bool blocked;

public:

    Crate(Point center, int w, int h);

    void draw() override;

};


#endif //F202_CRATE_H
