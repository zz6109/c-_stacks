#ifndef ARRARY_H
#define ARRARY_H
#include <iostream>
// #define ARRAYSIZE 100

class Array
{
// friend std::ostream &operator<<(std::ostream &out, const Array &rhs);

private:
    int *pArr_;

protected:  // 자식에서 접근 가능하게 만들어줌(메인은 안됨)
    static const int ARRAYSIZE;
    int size_;

public:
    static int getArraySize();
    // Array();
    explicit Array(int size = ARRAYSIZE);           // explicit(묵시적인) 헤더에서만 사용
    Array(const int *pArr, int size);
    Array(const Array& rhs);
    virtual ~Array();

    Array& operator=(const Array& rhs);

    bool operator==(const Array &rhs) const;

    virtual int& operator[](int index);              // overiding : 재정의한다

    virtual const int& operator[] (int index) const; // 재정의

    int size() const;
};

#endif
