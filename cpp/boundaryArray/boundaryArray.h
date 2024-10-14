#ifndef BOUNDARYARRAY_H
#define BOUNDARYARRAY_H
#include "safeArray.h"

template <typename T>
class BoundaryArray : public SafeArray<T>
{
private:
    int low_;

public:
    // BoundaryArray();
    explicit BoundaryArray(int size = Array::ARRAYSIZE);
    BoundaryArray(int low, int high);
    BoundaryArray(const T *pArr, int size, int low);

    // ~BoundaryArray();

    bool operator==(const BoundaryArray<T> &rhs) const;

    T &operator[](int index);
    const T &operator[](int index) const;

    int lower() const;

    int upper() const;
};

template <typename T>
BoundaryArray<T>::BoundaryArray(int size)
    : SafeArray<T>(size)
{
    low_ = 0;
}

template <typename T>
BoundaryArray<T>::BoundaryArray(int low, int high)
    : SafeArray<T>(high - low + 1)
{
    low_ = low;
}
template <typename T>
BoundaryArray<T>::BoundaryArray(const T *pArr, int size, int low)
    : SafeArray(pArr, size)
{
    low_ = low;
}
template <typename T>
bool BoundaryArray<T>::operator==(const BoundaryArray<T> &rhs) const
{
    return this->SafeArray<T>::operator==((SafeArray)rhs);
}
template <typename T>
T& BoundaryArray<T>::operator[](int index)
{
    if (index < low_ || index > upper()) {
        throw std::out_of_range("Index out of range");
    }
    return SafeArray<T>::operator[](index - low_);
}
template <typename T>
const T& BoundaryArray<T>::operator[](int index) const
{
    if (index < low_ || index > upper()) {
        throw std::out_of_range("Index out of range");
    }
    return SafeArray<T>::operator[](index - low_);
}
template <typename T>
int BoundaryArray<T>::lower() const
{
    return low_;
}
template <typename T>
int BoundaryArray<T>::upper() const
{
    return low_ + SafeArray<T>::size() - 1;
}
#endif