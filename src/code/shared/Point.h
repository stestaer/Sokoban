//
// Created by sacha on 10-11-22.
//

#include <iostream>

#ifndef F202_PROJET_POINT_H
#define F202_PROJET_POINT_H


class Point {
    
    
public:

    int y;
    int x;

    friend std::ostream& operator<<(std::ostream& os, const Point& p);

};


#endif //F202_PROJET_POINT_H
