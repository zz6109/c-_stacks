#ifndef SHAPE_H
#define SHAPE_H

class Shape
{
private:
    int x_;
    int y_;
public:
    Shape(int x, int y);
    void move(int offsetX, int offsetY);
    virtual ~Shape() {} 

    void move(int offsetX, int offsetY);
    virtual double area() const = 0;
};


#endif