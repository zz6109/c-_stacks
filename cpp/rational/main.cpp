#include <iostream>
#include "rational.h"

using namespace std;

int main()
{
    Rational r1(3, 2);

    cout << " "<< r1.numerator() << "\n---\n" << " " << r1.denominater() << endl;
    cout << "두 값의 최대공약수 : " << r1.Common_divisor() << endl;

    r1.abbreviation();
    cout << " "<< r1.numerator() << "\n---\n" << " " << r1.denominater() << endl;
    
    return 0;
}