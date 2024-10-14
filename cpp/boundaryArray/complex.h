#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>

class Complex;

std::ostream& operator<<(std::ostream& out, const Complex& rhs);

class Complex
{
friend std::ostream& operator<<(std::ostream& out, const Complex& rhs); // 전역함수, 프렌드함수 / 멤버함수X

private:
    // 내부구현
    double re_;      // 실수부
    double im_;      // 허수부

public: 
    Complex(double re_ = 0.0, double im_ = 0.0);  // 얘혼자 5인분

    Complex& operator+=(const Complex& rhs);

    double real(double re);
    double imag(double im);

    double real() const;
    double imag() const;

    bool operator==(const Complex &rhs) const;     // C언어에서는 참 거짓이 1, 0(int타입), C++에서는 참 거짓이 true, false(bool타입)
    bool operator!=(const Complex &rhs) const;


    const Complex operator+(const Complex& rhs) const;  // read only 함수는 const를 붙인다.

    const Complex& operator++();

    const Complex operator++(int );
};

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


#endif