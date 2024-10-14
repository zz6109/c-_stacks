#ifndef RATIONAL_H
#define RATIONAL_H

class Rational
{
private:
    int deno;   // 분모 
    int nume;   // 분자
    double res; // 계산된 유리수

public:
    Rational(int deno, int nume);
    ~Rational();

    int denominater();
    int numerator();

    void denominater(int deno);
    void numerator(int nume);

    int Common_divisor();  // 공약수 계산

    void abbreviation(); // 공약수로 약분한 값 저장 deno, nume 
};




#endif
