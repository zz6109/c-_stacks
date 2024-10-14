#include "string.h"
#include "stringRep.h"
#include <cstring>
#include <cassert>

std::ostream &operator<<(std::ostream &out, const String &rhs)
{
    // return out << rhs.ptr_->str_;
    return out << rhs.c_str();
}

String::String()
    : ptr_(new StringRep)
{
    assert(ptr_ );   
    ptr_->rc_ = 1;
}

String::String(const char *s)
    : ptr_(new StringRep(s))
{
    ptr_->rc_ = 1;
    assert(ptr_ );
}

String::String(const String &rhs)
    : ptr_(rhs.ptr_)
{
    assert(ptr_ );
    
}


String::~String() 
{
    --ptr_->rc_;
    if (ptr_->rc_ == 0){
        delete ptr_;
    }
    
}
String &String::operator=(const String &rhs) // deep copy를 고려해서 만들어 주어야함
{
    if (this != &rhs) // 자기자신복사 허용
    {
        --ptr_->rc_;
        if (ptr_->rc_ == 0)
        {
            delete ptr_;
        }
        ptr_ = rhs.ptr_;
        ++ptr_->rc_;
    }

    return *this;
}

// const char *String::c_str() const
// {
//     return str_;
// }

// int String::length() const
// {
//     return len_;
// }

bool String::operator==(const String &rhs) const
{
    return strcmp(ptr_->str_, rhs.ptr_->str_) == 0;
}

const String String::operator+(const String &rhs) const
{
    char buf[ptr_->len_ + rhs.ptr_->len_ +1];
    strcpy(buf, ptr_->str_);
    strcat(buf, rhs.ptr_->str_);

    String result(buf);

    return result;
}