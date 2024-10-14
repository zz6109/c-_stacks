#include <iostream>
#include "complex.h"
#include "stack.h"
#include "array.h"

int main()
{
    Stack<int> s1;
    s1.push(100);
    s1.push(100);
    s1.push(100);

    std::cout << "s1 1st pop() : " << s1.pop() << std::endl;
    std::cout << "s1 2st pop() : " << s1.pop() << std::endl;
    std::cout << "s1 3st pop() : " << s1.pop() << std::endl;

    Stack<Complex> s2;
    s2.push(Complex(3.0, 4.0));
    s2.push(Complex(5.0, 6.0));
    s2.push(Complex(7.0, 8.0));

    std::cout << "s1 1st pop() : " << s2.pop() << std::endl;
    std::cout << "s1 2st pop() : " << s2.pop() << std::endl;
    std::cout << "s1 3st pop() : " << s2.pop() << std::endl;    
}
