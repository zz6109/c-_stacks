#ifndef RATIONAL_CLASS
#define RATIONAL_CLASS
#include <iostream>

class Rational
{
private:
    long num;
    long den;

    long gcd(long u, long v);

public:
    Rational();
    Rational(long n, long d = 1);

    // ~Rational(); 컴파일러가 생성해줌
    // Rational& operator=(const Rational& rhs);

    Rational &operator=(long rhs);

    long numerator() const;
    long denominator() const;

    Rational operator+() const;
    Rational operator-() const;

    Rational invert() const;

    const Rational &operator+=(const Rational &rhs);
    const Rational &operator-=(const Rational &rhs);
    const Rational &operator*=(const Rational &rhs);
    const Rational &operator/=(const Rational &rhs);

    const Rational &operator+=(long rhs);
    const Rational &operator-=(long rhs);
    const Rational &operator*=(long rhs);
    const Rational &operator/=(long rhs);

    const Rational &operator++();
    const Rational operator++(int);
    const Rational &operator--();
    const Rational operator--(int);

    /*
    멤버함수는 this의 값을 1개(좌변)의 매개변수로 가지기 때문에 두개의 매개변수를
    가지려면 비멤버 함수로 선언 해야한다.
    */

    friend const Rational operator+(const Rational &l, const Rational &r);
    friend const Rational operator-(const Rational &l, const Rational &r);
    friend const Rational operator*(const Rational &l, const Rational &r);
    friend const Rational operator/(const Rational &l, const Rational &r);

    friend bool operator==(const Rational &lhs, const Rational &rhs);
    friend bool operator!=(const Rational &lhs, const Rational &rhs);
    friend bool operator<=(const Rational &lhs, const Rational &rhs);
    friend bool operator>=(const Rational &lhs, const Rational &rhs);
    friend bool operator<(const Rational &lhs, const Rational &rhs);
    friend bool operator>(const Rational &lhs, const Rational &rhs);

    friend std::ostream& operator<< (std::ostream& s, const Rational& r);

    Rational rabs(const Rational& rhs);
};

inline Rational &Rational::operator=(long rhs)
{
    num = rhs;
    den = 1;
    return *this;
}

inline double toDouble(const Rational &r)
{
    return double(r.numerator()) / r.denominator();
}

inline long trunc(const Rational &r)
{
    return r.numerator() / r.denominator();
}
inline long floor(const Rational &r)
{
    long q = r.numerator() / r.denominator();
    return (r.numerator() < 0 && r.denominator() != 1) ? --q : q;
}
inline long ceil(const Rational &r)
{
    long q = r.numerator() / r.denominator();
    return (r.numerator() >= 0 && r.denominator() != 1) ? ++q : q;
}

Rational toRational(double x, int iterations = 5);

#endif