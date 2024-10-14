#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>

class Complex;

// `friend` 함수 선언은 클래스 이름과 일치해야 합니다.
std::ostream& operator<<(std::ostream& out, const Complex& rhs);
// std::ostream& operator<<(std::ostream& out, const Complex& rhs);    // private에 접근 불가

class Complex
{
friend std::ostream& operator<<(std::ostream& out, const Complex& rhs); // 전역함수, 프렌드함수 / 멤버함수X

private:
    // 내부구현
    double re_;      // 실수부
    double im_;      // 허수부

public: 
    // Complex(); // 컴파일러가 주석된 선언을 제공해준다.
    // Complex(double re); // 이건 아님
    Complex(double re_ = 0.0, double im_ = 0.0);  // 얘혼자 5인분
    // Complex(Const Complex& rhs); // 복사연산자
    // ~Complex();


    // Complex& operator=(const Complex& rhs);  // 치환연산자

    // Complex& operator&();
    // const Complex& operator&() const 
    

    // Complex에서 사용 가능한 연산자들
    // += -= *= /= 0 %= X
    // &= |= ^= <<= >>= X
    //+ - * / 0       % X
    // ++ --            X
    // == != > < >= <=  0
    // && || !          X 

    Complex& operator+=(const Complex& rhs);

    double real(double re);
    double imag(double im);

    double real() const;
    double imag() const;

    bool operator==(const Complex &rhs) const;     // C언어에서는 참 거짓이 1, 0(int타입), C++에서는 참 거짓이 true, false(bool타입)
    bool operator!=(const Complex &rhs) const;


    const Complex operator+(const Complex& rhs) const;  // read only 함수는 const를 붙인다.
    // const Complex operator-(const Complex& rhs) const;     // 구현 X
    // const Complex operator*(const Complex& rhs) const;
    // const Complex operator/(const Complex& rhs) const;

    const Complex& operator++();

    const Complex operator++(int );
};



#endif