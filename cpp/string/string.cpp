#include "string.h"
#include <cstring>
#include <cassert>

std::ostream &operator<<(std::ostream &out, const String &rhs)
{
    return out << rhs.str_ << std::endl;
}

String::String()
    : str_(new char[1]), len_(0)
{
    assert(str_);
    str_[0] = '\0';
}

String::String(const char *s)
    : str_(new char[strlen(s) + 1]), len_(strlen(s))
{
    assert(str_);
    strcpy(str_, s);
}

String::String(const String &rhs)
    : str_(new char[rhs.len_ + 1]), len_(rhs.len_)
{
    assert(str_);
    strcpy(str_, rhs.str_);
}

String::~String()
{
    delete[] str_;
}

String &String::operator=(const String &rhs) // deep copy를 고려해서 만들어 주어야함
{
    if (this != &rhs) // 자기자신복사 허용
    {
        delete[] str_;             // 값 소거
        str_ = new char[rhs.len_ +1]; // 값 재 입력
        assert(str_);
        strcpy(str_, rhs.str_);
        len_ = rhs.len_;
    }

    return *this;
}

const char *String::c_str() const
{
    return str_;
}

int String::length() const
{
    return len_;
}

bool String::operator==(const String &rhs) const
{
    return strcmp(str_, rhs.str_) == 0;
}

const String String::operator+(const String &rhs) const
{
    char *buf = new char[len_ + rhs.len_ +1];
    strcpy(buf, str_);
    strcat(buf, rhs.str_);

    String result(buf);
    delete [] buf;
    return result;
}