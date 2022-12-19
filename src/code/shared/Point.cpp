//
// Created by sacha on 10-11-22.
//

#include "Point.h"

std::ostream& operator<<(std::ostream& os, const Point& p)
{
    os << "x,y: " << p.x << ", " << p.y;
    return os;
}