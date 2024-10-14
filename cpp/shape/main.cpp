#include <iostream>
#include "shape.h"
#include "rectangle.h"
#include "circle.h"
void printShape(const Shape *ps)
{
    if (typeid(*ps) == typeid(Rectangle))
    {
        std::cout << "rectangle area : " << ps->area();
        Rectangle *pr = (Rectangle *)ps;
        std::cout << "diagonal : " << pr->getDiagonal() << std::endl;
    }
    else if (typeid(*ps) == typeid(Circle))
    {
        std::cout << "circle area : " << ps->area() << ", ";
        Circle *pc = (Circle *)ps;
        std::cout << "Circumference : " << pc->getCircumference() << std::endl;
    }
    
}

int main()
{
    // Shape s(100, 100);  // 추상 클래스 타입의 객체는 만들수 없다
    // Shape *pc;          // 포인터는 가능하다

    Shape *pShapes[5];
    pShapes[0] = new Rectangle(100, 100, 10, 5);
    pShapes[1] = new Circle(10, 10, 10);
    pShapes[2] = new Rectangle(50, 50, 50, 50);
    pShapes[3] = new Rectangle(200, 200, 50, 10);
    pShapes[4] = new Circle(20, 20, 5);

    for (int i = 0; i < 5; i++)
    {
        printShape(pShapes[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        delete pShapes[i];
    }
    
    return 0;
}