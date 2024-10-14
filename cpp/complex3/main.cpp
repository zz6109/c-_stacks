#include <iostream>
#include "complex.h"
using namespace std;

int main()
{
    Complex c1;    
    Complex c2 = 3.0;
    Complex c3(3.0, 4.0);
    Complex c4 = c3;            // Complex c4(c3);
    
    
    c1 = c2 = c3;   // daisy-chain      

    if (c1 == c3)                            
    {
        cout << "c1과 c3가 같다." << endl;
    }
    else
    {
        cout << "c1과 c3가 같지 않다." << endl;
    }

    cout << c1 << endl; // cout.operator << (c1) or operator << (cout, c1)  전역함수로 연산자 중복을 해줘야함(라이브러리를 수정할수 없기 때문)
    
    Complex c5;
    c5 = c2 + c3;

    cout << c5 << endl; 

    return 0;
}