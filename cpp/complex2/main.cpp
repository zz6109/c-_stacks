#include <iostream>
#include "complex.h"
using namespace std;

int main()
{
    Complex c1;    
    // Complex c2(3.0);
    // 윗 코드와 밑 코드는 동작이 같다. 
    Complex c2 = 3.0;
    Complex c3(3.0, 4.0);
    Complex c4 = c3;            // Complex c4(c3);

    c3.real(c1.real());
    c1.imag(c3.imag());

    // if (c1.real() == c3.real() && c1.imag() == c3.imag())

    // if (c1.operator== (&c3)) // 1 | c1.operator=(c3) or operator=(c1, c3) 

    // if (c1 == &c3)           // 3 | c1.operator=(&c3)              

    if (c1 == c3)               // 2 |  c1.operator=(c3) or operator=(c1, c3)                
    {
        cout << "c1과 c3가 같다." << endl;
    }
    else
    {
        cout << "c1과 c3가 같지 않다." << endl;
    }

    cout << "c1 : (" << c1.real() << ", " << c1.imag() << "i)" << endl;
    cout << "c2 : (" << c2.real() << ", " << c2.imag() << "i)" << endl;
    cout << "c3 : (" << c3.real() << ", " << c3.imag() << "i)" << endl; 

    return 0;
}