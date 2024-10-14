#include <iostream>
#include "rational.h"

using namespace std;

int main()
{
    Rational r1(7, 4);
    Rational r2(8, 3);
    Rational r3 = r1;

    cout << r1;                          // r1 분수형으로 출력
    cout << r1.Common_divisor() << endl; // r1의 최대공약수 출력
    r1.abbreviation();
    cout << r1 << endl; // 약분된 r1 출력

    cout << r2;                          // r2 분수형으로 출력
    cout << r2.Common_divisor() << endl; // r2의 최대 공약수 출력
    r2.abbreviation();
    cout << r2 << endl; // 약분된 r2 출력

    if (r1 == r3)
    {
        cout << "r1과 r3가 같다." << endl;
    }
    else
    {
        cout << "r1과 r3가 같지 않다." << endl;
    }

    cout << endl;
    Rational r4;
    r4 = r1 + r2;

    // r4.Common_divisor();
    // r4.abbreviation();
    cout << r4 << endl;

    r4 = r1 - r2;
    cout << r4 << endl << endl;

    r4++;
    cout << r4 << endl;
    ++r4;
    cout << r4 << endl;
    return 0;
}