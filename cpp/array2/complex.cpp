#include <iostream>
#include "complex.h"

std::ostream& operator<<(std::ostream& out, const Complex& rhs)
{
    return out << "(" << rhs.re_ << ", " << rhs.im_ << "i)";
}

Complex::Complex(double re, double im)  // 변수를 입력값으로 초기화
: re_(re), im_(im)                      // constructor initialization List(초기화)
{
    // /*this->*/ re_ = re; // 받아오는 변수와 멤버함수가 다르면 this->를 생략할수 있다.
    // /*this->*/ im_ = im;
}

Complex& Complex::operator+=(const Complex &rhs)
{
    re_ += rhs.re_;
    im_ += rhs.im_;

    return *this;
}

bool Complex::operator==(const Complex &rhs) const
{
    return re_ == rhs.re_ && im_ == rhs.im_;
}

bool Complex::operator!=(const Complex &rhs) const
{
    return !this->operator==(rhs);
}

const Complex Complex::operator+(const Complex& rhs) const
{
    Complex result(re_ + rhs.re_, im_ + rhs.im_);

    return result;
}

const Complex& Complex::operator++()
{
    re_ = re_ + 1;

    return *this;
}

const Complex Complex::operator++(int )
{
    Complex tmp = *this;

    re_ = re_ + 1;

    return tmp;
}

double Complex::real(double re)
{
    return re_ = re;
}
double Complex::imag(double im)
{
    return im_ = im;
}

double Complex::real() const
{
    return re_;
}
double Complex::imag() const
{
    return im_;
}
