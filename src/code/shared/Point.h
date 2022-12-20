//
// Created by sacha on 10-11-22.
//
#ifndef F202_PROJET_POINT_H
#define F202_PROJET_POINT_H

#include <iostream>



class Point {
    
    
public:

    int y;
    int x;

    friend std::ostream& operator<<(std::ostream& os, const Point& p);

    Point operator+ (const Point& p) const;
};


#endif //F202_PROJET_POINT_H
