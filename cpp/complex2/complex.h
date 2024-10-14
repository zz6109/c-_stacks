#ifndef COMPLEX_H
#define COMPLEX_H

class Complex
{
private:
    // 내부구현
    double re;      // 실수부
    double im;      // 허수부

public:
    // 멤버 변수
    // 멤버 함수
    Complex();                      //function overloading | default construct
    Complex(double re);             // --> 'one-interface multi-method' | convert construct
    Complex(double re, double im);
    // C언어와 다르게 C++은 함수를 중복해서 선언할수 있다.(인자타입, 인자갯수가 달라야함)
    Complex(const Complex &rc);     // copy construct
    ~Complex();

    //void operator==(const Complex &rc);

    bool operator==(const Complex &rc);     // C언어에서는 참 거짓이 1, 0(int타입), C++에서는 참 거짓이 true, false(bool타입)

    double real();                  //getset func
    double imag();
    void real(double real);
    void imag(double imag);
};



#endif