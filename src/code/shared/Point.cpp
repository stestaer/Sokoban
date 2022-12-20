//
// Created by sacha on 10-11-22.
//

#include "Point.h"

std::ostream& operator<<(std::ostream& os, const Point& p)
{
    os << "x,y: " << p.x << ", " << p.y;
    return os;
}

Point Point::operator+(const Point &p) const
{
    Point result{0,0};
    result.y = this->y + p.y;
    result.x = this->x + p.x;
    return result;
}