#ifndef CIRCLE_H
#define CIRCLE_H

class Circle
{
private:
    int radius;
public:
    Circle(int x, int y, int r);
    // ~Circle();
    double area();
    double getCircumference();
};


#endif