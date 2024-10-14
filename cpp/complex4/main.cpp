#include <iostream>
#include "complex.h"
using namespace std;

int main()
{
    Complex c1;    
    Complex c2 = 3.0;
    Complex c3(3.0, 4.0);
    Complex c4 = c2;            // Complex c4(c2);
    
    c1.real(c3.real());
    c3.imag(c1.imag());
    c1 = c3;   // daisy-chain      

    if (c1 == c3)                            
    {
        cout << "c1과 c3가 같다." << endl;
    }
    else
    {
        cout << "c1과 c3가 같지 않다." << endl;
    }

    cout << c1 << endl << endl; // cout.operator << (c1) or operator << (cout, c1)  전역함수로 연산자 중복을 해줘야함(라이브러리를 수정할수 없기 때문)
    
    c1 += c2;

    const Complex c5 = c1 + c2;
    // c5 = c2 + c3;    c5가 const라서 값 변경 못함

    c1++;   // 더하기전 값을 임시로 저장하고 더한단
    ++c2;   // 

    cout << c1 << endl; 
    cout << c2 << endl << endl; 
    cout << c5 << endl; 
    cout << c5.real() << ", " << c5.imag() << endl;

    return 0;
}