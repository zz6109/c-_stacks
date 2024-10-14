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
    double re;      // 실수부
    double im;      // 허수부

public: 
    Complex(double re = 0.0, double im = 0.0);  // default인자는 뒷쪽부터 써야한다
    // C언어와 다르게 C++은 함수를 중복해서 선언할수 있다.(인자타입, 인자갯수가 달라야함)
    Complex(const Complex &rhs);     // copy construct
    ~Complex();

    Complex& operator=(const Complex &rhs);

    bool operator==(const Complex &rhs);     // C언어에서는 참 거짓이 1, 0(int타입), C++에서는 참 거짓이 true, false(bool타입)
    bool operator!=(const Complex &rhs);


    const Complex operator+(const Complex& rhs);
};



#endif