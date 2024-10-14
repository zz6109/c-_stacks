#include <iostream>
#include <string>

int main()
{
    {
        const std::string s = "a string";
        std::cout << s << std::endl;
        {
            const std::string s = "b string";
            std::cout << s << std::endl;
        };
    }
    return 0;
}