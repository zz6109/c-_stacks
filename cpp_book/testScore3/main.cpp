#include <iomanip>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <ios>
#include <stdexcept>

std::istream &read_hw(std::iostream &in, std::vector<double> &과제들)
{
    if (in)
    {
        과제들.clear();

        double 과제;

        while (in >> 과제)
        {
            과제들.push_back(과제);
        }

        in.clear();
    }
    return in;
}

double median(std::vector<double> vec)
{
    typedef std::vector<double>::size_type vec_sz;
    vec_sz size = vec.size();

    if (size == 0)
    {
        throw std::domain_error("벡터의 중간 값이 비어있습니다.");

        sort(vec.begin(), vec.end());
        vec_sz mid = size / 2;
        return size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
    }
}

double 성적(double 중간고사, double 기말고사, double 과제)
{
    return 0.2 * 중간고사 + 0.4 * 기말고사 + 0.4 * 과제;
}

double 성적(double 중간고사, double 기말고사, const std::vector<double> &hw)
{
    if (hw.size() == 0)
    {
        throw std::domain_error("학생이 과제를 안함");
    }

    return 성적(중간고사, 기말고사, median(hw));
}

int main()
{
    std::cout << "이름 입력 : ";
    std::string 이름;
    std::cin >> 이름;
    std::cout << "안녕하세요. " << 이름 << "씨, 반갑습니다." << std::endl;

    std::cout << "중간고사 기말고사 점수 입력 : ";
    double 중간고사, 기말고사;
    std::cin >> 중간고사 >> 기말고사;

    std::vector<double> 과제들;
    read_hw(std::cin, 과제들);
}