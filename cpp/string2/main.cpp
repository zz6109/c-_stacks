#include <iostream>
#include "string.h"

int main()
{
    String s1;
    String s2 = "hello";
    String s3 = s2;

    s1 = s3;

    if (s1 == s3)
    {
        std::cout << "S1 == S3" << std::endl;
    }
    else
    {
        std::cout << "S1 != S3" << std::endl;
    }

    String s4 = ", world";

    s1 = s2 + s4;
    
    
    std::cout << "s1 : " << s1.c_str() << std::endl;
    std::cout << "s1 : " << s1.length() << std::endl;
    return 0;
}
