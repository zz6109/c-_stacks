#include <iostream>
#include "complex.h"

Complex::Complex()
{
    this->im = 0.0;
    this->re = 0.0;
}

Complex::Complex(double re)
{
    this->re = re;
    this->im = 0.0;
}

Complex::Complex(double re, double im)  // 변수를 입력값으로 초기화
{
    this->re = re;
    this->im = im;
}

Complex::~Complex() // c1은 지역변수기 때문에 괄호에 아무것도 들어 가지 않음, 전역변수를 삭제해줘야할때 뭔가를 씀
{
}

double Complex::real()  // 입력된 변수값을 반환
{
    return this->re;
}

double Complex::imag()
{
    return this->im;
}

void Complex::real(double re)
{
    this->re = re;
}

void Complex::imag(double re)
{
    this->im = im;
}