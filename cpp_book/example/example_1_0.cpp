#include <iostream>
#include <string>

int main()
{
    std::cout << "input name: ";

    std::string name;
    std::cin >> name;

    std::string greeting = "Hello, " + name + "!";

    std::string spaces(greeting.size(), ' ');

    std::string second = "* " + spaces + " *";

    std::string first(second.size(), '*');

    std::cout << first << std::endl;
    std::cout << second << std::endl;
    std::cout << "* " + greeting + " *" << std::endl;
    std::cout << second << std::endl;
    std::cout << first << std::endl;

    return 0;
}