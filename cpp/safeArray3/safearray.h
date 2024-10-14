#ifndef SAFEARRAY_H
#define SAFEARRAY_H
#include "array.h"

template <typename T>
class SafeArray : public Array<T>  // 부모쪽에 퍼블릭이 자식 퍼블릭에 온다
                                // 자식은 부모의 private에 접근할수 없다
{
private:
    
public:
    explicit SafeArray(int size = Array<T>::getArraySize());
    SafeArray(const int *pArr, int size);
    SafeArray(const SafeArray<T>& rhs);
    ~SafeArray();

    SafeArray<T>& operator=(const SafeArray<T>& rhs);

    bool operator==(const SafeArray<T>& rhs) const;

    int& operator[] (int index);
    const int& operator[] (int index) const;

    // int size() const;
};

template <typename T>
SafeArray<T>::SafeArray(int size)
: Array<T>(size)   // Array쪽 생성자 호출
{
}
template <typename T>
SafeArray<T>::SafeArray(const T *pArr, int size)
    : Array<T>(pArr, size)
{
}
template <typename T>
SafeArray<T>::SafeArray(const SafeArray<T> &rhs)
    : Array<T>( (Array)rhs)    //slicing
{
}
template <typename T>
SafeArray<T>::~SafeArray()
{
    // delete[] pArr_; 자동호출
}
template <typename T>
SafeArray<T> &SafeArray<T>::operator=(const SafeArray<T> &rhs)
{
    this->Array<T>::operator==( (Array<T>)rhs);
    return *this;
}
template <typename T>
bool SafeArray<T>::operator==(const SafeArray<T> &rhs) const
{
    return this->Array<T>::operator==( (Array<T>)rhs);
}
template <typename T>
T& SafeArray<T>::operator[](int index)
{
    assert(index >= 0 && index < this->Array<T>::size_);

    return this->Array<T>::operator[](index);
}
template <typename T>
const int &SafeArray<T>::operator[](int index) const
{
    assert(index >= 0 && index < this->Array<T>::size_);

    return this->Array<T>::operator[](index);
}

#endif