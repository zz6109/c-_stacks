#include "safearray.h"
#include <cassert>

// const int SafeArray::ARRAYSIZE = 100;

SafeArray::SafeArray(int size)
: Array(size)   // Array쪽 생성자 호출
{
}
SafeArray::SafeArray(const int *pArr, int size)
    : Array(pArr, size)
{
}
SafeArray::SafeArray(const SafeArray &rhs)
    : Array( (Array)rhs)    //slicing
{
}
SafeArray::~SafeArray()
{
    // delete[] pArr_; 자동호출
}

SafeArray &SafeArray::operator=(const SafeArray &rhs)
{
    this->Array::operator==( (Array)rhs);
    return *this;
}

bool SafeArray::operator==(const SafeArray &rhs) const
{
    return this->Array::operator==( (Array)rhs);
}

int &SafeArray::operator[](int index)
{
    assert(index >= 0 && index < this->Array::size_);

    return this->Array::operator[](index);
}
const int &SafeArray::operator[](int index) const
{
    assert(index >= 0 && index < this->Array::size_);

    return this->Array::operator[](index);
}

// int SafeArray::size() const
// {
//     return size_;
// }