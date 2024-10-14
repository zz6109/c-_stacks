#ifndef STRINGREP_H
#define STRINGREP_H

class StringRep
{
friend class String;
// private: class는 기본적으로 프라이빗이고 struct는 기본적으로 퍼블릭이다.
    char *str_;
    int len_;
    int rc_;     // reference count

    StringRep();
    StringRep(const char *s);
    StringRep(const StringRep& rhs);
    ~StringRep();

};

#endif