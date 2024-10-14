#ifndef ARRARY_H
#define ARRARY_H
#include <iostream>
// #define ARRAYSIZE 100

class Array
{
// friend std::ostream &operator<<(std::ostream &out, const Array &rhs);

private:
    static const int ARRAYSIZE;

    int *pArr_;
    int size_;


public:
    // Array();
    explicit Array(int size = ARRAYSIZE);           // explicit(묵시적인) 헤더에서만 사용
    Array(const int *pArr, int size);
    Array(const Array& rhs);
    ~Array();

    Array& operator=(const Array& rhs);

    bool operator==(const Array &rhs) const;

    int& operator[](int index);

    const int& operator[] (int index) const; 

    int size() const;
};

#endif
