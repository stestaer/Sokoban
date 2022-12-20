//
// Created by sacha on 11-12-22.
// Text class took from Lab3
#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Box.H>

#ifndef F202_TEXT_H
#define F202_TEXT_H

#include <string>
#include "../shared/Point.h"


class Text {
    std::string s;
    Point center;
    int fontSize;
    Fl_Color color;

public:
    // Constructor
    Text(std::string s, Point center, int fontSize = 10, Fl_Color color = FL_BLACK):
            s{s}, center{center}, fontSize{fontSize}, color{color} {}

    // Draw
    void draw();

    // Setters and getters
    std::string getString() {
        return s;
    }
    void setString(const std::string &newString) {
        s = newString;
    }
    int getFontSize() {
        return fontSize;
    }
    void setFontSize(int newFontSize) {
        fontSize = newFontSize;
    }
    Point getCenter() {
        return center;
    }
    void setCenter(Point newCenter) {
        center = newCenter;
    }
};


#endif //F202_TEXT_H
