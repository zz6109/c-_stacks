#include <iostream>
#include <string>

int main()
{
    // :: scope resolution operator
    std::cout << "입력 : ";
    // 식의 결과 값 : cout, 부효과 : "입력" 화면상에 출력

    std::string value;
    std::cin >> value;

    std::cout << "입력값 : " << value << std::endl;
    return 0;
}