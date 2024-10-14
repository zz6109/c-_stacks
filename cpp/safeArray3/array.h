#ifndef ARRARY_H
#define ARRARY_H
#include <iostream>
#include <cassert>
template <typename T>
class Array<T>
{

private:
    T *pArr_;

protected:  // 자식에서 접근 가능하게 만들어줌(메인은 안됨)
    static const int ARRAYSIZE;
    int size_;

public:
    static int getArraySize();
    // Array();
    explicit Array(int size = ARRAYSIZE);           // explicit(묵시적인) 헤더에서만 사용
    Array(const T *pArr, int size);
    Array(const Array& rhs);
    virtual ~Array();

    Array& operator=(const Array& rhs);

    bool operator==(const Array &rhs) const;

    virtual int& operator[](int index);              // overiding : 재정의한다

    virtual const int& operator[] (int index) const; // 재정의

    int size() const;
};

const int Array::ARRAYSIZE = 100;

int Array::getArraySize()
{
   return Array::ARRAYSIZE;
}

/*
Array::Array()
: pArr_(new int[100]), size_(100)
{
   assert(pArr_ );
}
*/
template <typename T>
Array::Array(int size)
: pArr_(new int[size]), size_(size)
{
   assert(pArr_ );
}

template <typename T>
Array::Array(const int *pArr, int size)
: pArr_(new int[size]), size_(size)
{
   assert(pArr_ );
  
   for(int i=0; i<size; ++i){
      pArr_[i] = pArr[i];
   }
}

template <typename T>
Array::Array(const Array& rhs)
: pArr_(new int[rhs.size_]), size_(rhs.size_)
{
   assert(pArr_ );
  
   for(int i=0; i<size_; ++i){
      pArr_[i] = rhs.pArr_[i];
   }
}

template <typename T>
Array::~Array(){
   delete [] pArr_;
}

template <typename T>
Array& Array::operator=(const Array& rhs){
   if(this != &rhs){
      delete [] pArr_;
      pArr_ = new int[rhs.size_];
      assert(pArr_ );
      size_=rhs.size_;
     
      for(int i=0; i<size_; ++i){
         pArr_[i] = rhs.pArr_[i];
      }
   }
  
   return *this;
}

template <typename T>
bool Array::operator==(const Array& rhs) const{
   if(size_ != rhs.size_){
      return false;
   }
  
   int i;
   for(i=0; i<rhs.size_; ++i){
      if(pArr_[i] != rhs.pArr_[i]){
      break;
      }
   }
  
   return (i == rhs.size_);
}

template <typename T>
int& Array::operator[](int index){
   return pArr_[index];
}

template <typename T>
const int& Array::operator[](int index) const{
   return pArr_[index];
}

template <typename T>
int Array::size() const{
   return size_;
} 
#endif
