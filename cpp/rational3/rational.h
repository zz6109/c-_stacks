#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>

class Rational
{
friend std::ostream& operator<<(std::ostream& out, const Rational& rhs);

private:
    int deno;   // 분모 
    int nume;   // 분자
    int res; // 계산된 유리수

public:
    Rational(int deno = 0, int nume = 0);   // default 
    ~Rational();

    // Rational(Rational r);       // 무한으로 복사 생성자가 호출된다. 쓰지마라.
    Rational(const Rational& rhs); // right-hand-side

    Rational& operator=(const Rational &rhs);   // getset함수 대체

    int Common_divisor();  // 공약수 계산

    void abbreviation();

    bool operator==(const Rational &rhs);
    bool operator!=(const Rational &rhs);

    const Rational operator+(const Rational& rhs);
    const Rational operator-(const Rational& rhs);
};




#endif
