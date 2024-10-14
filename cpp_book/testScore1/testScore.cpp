#include <iomanip>
#include <iostream>
#include <string>

int main()
{
    std::cout << "이름 입력 : ";
    std::string 이름;
    std::cin >> 이름;

    std::cout << "중간고사 기말고사 점수 입력 : ";
    double 중간고사, 기말고사;
    std::cin >> 중간고사 >> 기말고사;

    int 셈 = 0;
    double 합 = 0;
    double 과제;
    while (std::cin >> 과제)
    {
        ++셈;
        합 += 과제;
    }
    
    const double 최종점수 = 0.2 * 중간고사 + 0.4 * 기말고사 + 0.4 * 합 / 셈;

    std::streamsize prec = std::cout.precision();
    std::cout << "너의 최종 점수 : " << std::setprecision(3) << 최종점수 << std::setprecision(prec) << std::endl;

    return 0;
}