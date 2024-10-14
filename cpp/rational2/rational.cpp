#include "rational.h"
#include <cassert>

Rational::Rational(int deno, int nume)
{
    this->deno = deno;
    this->nume = nume;
    this->res = 0;
}

Rational::~Rational()
{
}

Rational::Rational(const Rational& rhs)
{
    this->nume = rhs.nume;
    this->deno= rhs.deno;
}

int Rational::denominater()
{   
    assert(deno );
    return this->deno;
}
int Rational::numerator()
{
    return this->nume;
}

void Rational::denominater(int deno)
{
    this->deno = deno;
}
void Rational::numerator(int nume)
{
    this->nume = nume;
}

int Rational::Common_divisor()   // 최대공약수로 약분 한 값을 저장
{
    int a, b, r;
    a = this->deno;
    b = this->nume;
    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    this->res = a;

    return this->res;   //최대 공약수를 res에 저장 
}

void Rational::abbreviation()
{
    this->deno = this->deno/this->res;
    this->nume = this->nume/this->res;
}

