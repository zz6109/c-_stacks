#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>
#include "gcd.h"

class Rational
{
friend std::ostream& operator<<(std::ostream& out, const Rational& rhs);

private:
    int deno_;      // 분모 
    int nume_;      // 분자
    int mcd_;       // 최대공약수

public:
    Rational(int deno_ = 0, int nume_ = 0, int mcd_ = 0);   // default 
    // ~Rational();

    // Rational(Rational r);       // 무한으로 복사 생성자가 호출된다. 쓰지마라.
    // Rational(const Rational& rhs); // right-hand-side

    Rational& operator=(const Rational &rhs);   // getset함수 대체

    int Common_divisor();   // 최대공약수 계산후 mcd_에 저장

    void abbreviation();    // 약분

    bool operator==(const Rational &rhs) const;
    bool operator!=(const Rational &rhs) const;

    const Rational& operator++();
    const Rational operator++(int ); // 함수 구분용으로 int삽입

    const Rational operator+(const Rational& rhs) const;
    const Rational operator-(const Rational& rhs) const;
};




#endif
