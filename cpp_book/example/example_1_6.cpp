#include <iostream>
#include <string>

int main()
{
    std::cout << "what's your name? ";
    std::string name;
    std::cin >> name;

    std::cout << "Hello, " << name << std::endl << "And what's yours? ";
    std::cin >> name;

    std::cout << "Hello, " << name << std::endl << "nice to meet you too!\n";
    return 0;
    
}