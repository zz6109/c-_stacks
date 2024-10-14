#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <cmath>

class Rectangle
{
private:
    int width_;
    int height_;

public:
    Rectangle(int x, int y, int w, int h);
    // ~Rectangle();

    double area() const;
    double getDiagonal() const;
};


#endif