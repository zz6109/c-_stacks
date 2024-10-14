#include "rational.h"
#include <cassert>

std::ostream& operator<<(std::ostream& out, const Rational& rhs)
{
    return out << " "<< rhs.nume << "\n---\n" << " " << rhs.deno << std::endl;
}

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

Rational& Rational::operator=(const Rational &rhs)   // Complex로 값을 받을려면 레퍼런스로 선언해야함
{
    this->deno = rhs.deno;
    this->nume = rhs.nume;

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

bool Rational::operator==(const Rational &rhs) 
{
    return this->deno == rhs.deno && this->nume == rhs.nume;
}

bool Rational::operator!=(const Rational &rhs)
{
    return !this->operator==(rhs);
}

const Rational Rational::operator+(const Rational& rhs)
{
    Rational result;

    if (this->deno == rhs.deno)
    {
        result.nume = this->nume + rhs.nume;
        result.deno = this->deno;
    }
    else if (this->deno != rhs.deno)
    {
        result.nume = this->nume * rhs.deno + rhs.nume * this->deno;
        result.deno = this->deno * rhs.deno;
    }
    
    
    // Rational result(this->deno + rhs.deno, this->nume + rhs.nume);

    return result;
}

const Rational Rational::operator-(const Rational& rhs)
{
    Rational result;

    if (this->deno == rhs.deno)
    {
        result.nume = this->nume - rhs.nume;
        result.deno = this->deno;
    }
    else if (this->deno != rhs.deno)
    {
        result.nume = this->nume * rhs.deno - rhs.nume * this->deno;
        result.deno = this->deno * rhs.deno;
    }    

    return result;
}

