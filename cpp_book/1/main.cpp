#include <iostream>
#include <vector>
#include <string>
#include <cctype>


bool isUpper(const std::string& s) {
    bool result = false;

    for (std::string::const_iterator it = s.cbegin(); it != s.cend(); ++it)
    {
        // if (*it>= 'A' && *it <= 'Z') 아래 if와 같은 기능
        if (isupper(*it)) 
        {
            result = true;
            break;
        }
        
    }
    return result;
}

int main()
{
    std::vector < std::string > lower, upper;

    std::string s;
    while (std::cin >> s)
    {
        if (isUpper(s))
        {
            upper.push_back(s);
        }
        else
        {
            lower.push_back(s);
        }
        
    }
    // 대문자로 시작하는 문자열 출력
    std::cout << "소문자만 들어있는 문자열:" << std::endl;
    for (std::vector<std::string>::const_iterator it = lower.cbegin(); it != lower.cend(); ++it) {
        std::cout << *it << std::endl;
    }

    // 소문자로 시작하는 문자열 출력
    std::cout << "대문자가 들어간 문자열:" << std::endl;
    for (auto it = upper.cbegin(); it != upper.cend(); ++it) {
        std::cout << *it << std::endl;
    }
    return 0;
}