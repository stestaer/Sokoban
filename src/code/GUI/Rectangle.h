//
// Created by sacha on 25-11-22.
//
// Rectangle class mainly took from Lab3

#ifndef F202_RECTANGLE_H
#define F202_RECTANGLE_H


class Rectangle {
    Point center;
    int w, h;
    Fl_Color fillColor, frameColor;

public:
    Rectangle(Point center, int w, int h,
              Fl_Color frameColor = FL_BLACK,
              Fl_Color fillColor = FL_WHITE);

    void draw();

    void setFillColor(Fl_Color newFillColor);

    Fl_Color getFillColor()
    {
        return fillColor;
    }

    void setFrameColor(Fl_Color newFrameColor);

    Fl_Color getFrameColor()
    {
        return frameColor;
    }

    void setWidth(int neww)
    {
        w = neww;
    }

    void setHeight(int newh)
    {
        h = newh;
    }

    int getWidth()
    {
        return w;
    }

    int getHeight()
    {
        return h;
    }

    bool contains(Point p);

    Point getCenter()
    {
        return center;
    }
};


#endif //F202_RECTANGLE_H
