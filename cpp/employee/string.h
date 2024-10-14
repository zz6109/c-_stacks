#ifndef STRING_H
#define STRING_H
#include <iostream>
class String
{
friend std::ostream& operator<<(std::ostream& out, const String& rhs);

private:
    char *str_;
    int len_;
public:
    String();
    String(const char *s);
    // 컴파일러가 자동으로 생성해줌(비어있으면 이게 있는게 보여야함)
    String(const String& rhs);
    ~String();

    // String* operator&()
    // const String* operator&()

    String& operator=(const String& rhs);

    const char* c_str() const;
    int length() const;

    bool operator==(const String& rhs) const;

    const String operator+(const String& rhs) const;
    
};



#endif
