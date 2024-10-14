#include <iostream>
#include "complex.h"

std::ostream& operator<<(std::ostream& out, const Complex& rhs)
{
    out << "(" << rhs.re << ", " << rhs.im << "i)";

    return out;
}

Complex::Complex(double re, double im)  // 변수를 입력값으로 초기화
{
    this->re = re;
    this->im = im;
}

Complex::Complex(const Complex& rc)
{
    this->re = rc.re;
    this->im = rc.im;
}

Complex::~Complex() // c1은 지역변수기 때문에 괄호에 아무것도 들어 가지 않음, 전역변수를 삭제해줘야할때 뭔가를 씀
{
}
Complex& Complex::operator=(const Complex &rhs)   // Complex로 값을 받을려면 레퍼런스로 선언해야함
{
    this->re = rhs.re;
    this->im = rhs.im;

    return *this;
}

bool Complex::operator==(const Complex &rhs) 
{
    return this->re == rhs.re && this->im == rhs.im;
}

bool Complex::operator!=(const Complex &rhs)
{
    return !this->operator==(rhs);
}

const Complex Complex::operator+(const Complex& rhs)
{
    Complex result(this->re + rhs.re, this->im + rhs.im);

    return result;
}
