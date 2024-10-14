#include "rational.h"
#include <cassert>

std::ostream &operator<<(std::ostream &out, const Rational &rhs)
{
    return out << " " << rhs.nume_ << "\n---\n"
               << " " << rhs.deno_ << std::endl;
}

Rational::Rational(int deno, int nume, int mcd)
    : deno_(deno), nume_(nume), mcd_(mcd) // 멤버변수 초기화 list
{
}

// Rational::Rational(const Rational& rhs)          // 복사 멤버함수
// {
//     this->nume_ = rhs.nume_;
//     this->deno_= rhs.deno_;
// }

Rational &Rational::operator=(const Rational &rhs) // Rational로 값을 받을려면 레퍼런스로 선언해야함(치환 멤버함수)
{
    deno_ = rhs.deno_;
    nume_ = rhs.nume_;

    return *this;
}

// Rational Common_divisor(Rational& rhs)   // 최대공약수로 약분 한 값을 저장
// {
//     int a, b, r;
//     a = rhs.deno;
//     b = rhs.nume;
//     while (b != 0) {
//         r = a % b;
//         a = b;
//         b = r;
//     }
//     rhs.res = a;

//     return rhs.res;   //최대 공약수를 res에 저장
// }

// Rational abbreviation(Rational& rhs)
// {
//     rhs.deno = rhs.deno/rhs.res;
//     rhs.nume = rhs.nume/rhs.res;
// }

int Rational::Common_divisor() // 최대공약수로 약분 한 값을 저장
{
    int a, b, r;
    a = deno_;
    b = nume_;
    while (b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    mcd_ = a;

    return mcd_; // 최대 공약수를 res에 저장
}

void Rational::abbreviation()
{
    deno_ = deno_ / mcd_;
    nume_ = nume_ / mcd_;
}

bool Rational::operator==(const Rational &rhs) const
{
    return deno_ == rhs.deno_ && nume_ == rhs.nume_;
}

bool Rational::operator!=(const Rational &rhs) const
{
    return !this->operator==(rhs);
}

const Rational Rational::operator+(const Rational &rhs) const
{
    Rational result;

    if (deno_ == rhs.deno_)
    {
        result.nume_ = nume_ + rhs.nume_;
        result.deno_ = deno_;
    }
    else if (deno_ != rhs.deno_)
    {
        result.nume_ = nume_ * rhs.deno_ + rhs.nume_ * deno_;
        result.deno_ = deno_ * rhs.deno_;
    }

    // Rational result(this->deno + rhs.deno, this->nume + rhs.nume);

    return result;
}

const Rational Rational::operator-(const Rational &rhs) const
{
    Rational result;

    if (deno_ == rhs.deno_)
    {
        result.nume_ = nume_ - rhs.nume_;
        result.deno_ = deno_;
    }
    else if (deno_ != rhs.deno_)
    {
        result.nume_ = nume_ * rhs.deno_ - rhs.nume_ * deno_;
        result.deno_ = deno_ * rhs.deno_;
    }

    return result;
}

const Rational& Rational::operator++()
{
    nume_ = nume_ + deno_;

    return *this;
}
const Rational Rational::operator++(int)
{
    Rational tmp = *this;
    nume_ = nume_ + deno_;

    return tmp;
}
