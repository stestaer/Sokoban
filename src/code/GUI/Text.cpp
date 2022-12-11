//
// Created by sacha on 11-12-22.
//

#include "Text.h"

void Text::draw() {
    fl_color(color);
    fl_font(FL_HELVETICA, fontSize);
    int width, height;
    fl_measure(s.c_str(), width, height, false);
    fl_draw(s.c_str(), center.x-width/2, center.y-fl_descent()+height/2);
}