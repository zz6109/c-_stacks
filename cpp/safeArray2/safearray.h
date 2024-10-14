#ifndef SAFEARRAY_H
#define SAFEARRAY_H
#include "array.h"

class SafeArray : public Array  // 부모쪽에 퍼블릭이 자식 퍼블릭에 온다
                                // 자식은 부모의 private에 접근할수 없다
{
private:
    // static const int ARRAYSIZE;

    // int* pArr_;
    // int size_;
public:
    explicit SafeArray(int size = Array::getArraySize());
    SafeArray(const int *pArr, int size);
    SafeArray(const SafeArray& rhs);
    ~SafeArray();

    SafeArray& operator=(const SafeArray& rhs);

    bool operator==(const SafeArray &rhs) const;

    int& operator[] (int index);
    const int& operator[] (int index) const;

    // int size() const;
};



#endif