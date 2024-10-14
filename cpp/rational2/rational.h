#ifndef RATIONAL_H
#define RATIONAL_H

class Rational
{
private:
    int deno;   // 분모 
    int nume;   // 분자
    int res; // 계산된 유리수

public:
    Rational(int deno, int nume);
    ~Rational();

    // Rational(Rational r);       // 무한으로 복사 생성자가 호출된다. 쓰지마라.
    Rational(const Rational& rhs); // right-hand-side

    int denominater();
    int numerator();

    void denominater(int deno);
    void numerator(int nume);

    int Common_divisor();  // 공약수 계산

    void abbreviation(); // 공약수로 약분한 값 저장 deno, nume 
};




#endif
