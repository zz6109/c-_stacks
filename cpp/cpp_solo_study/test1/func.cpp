#include "func.h"
#include <cstring>
#include <iostream>

// func::func(int max_num = 0, int decimal_num_ary[])
// : max_num_(max_num), decimal_num_ary_[](decimal_num_ary)[]
// {

// }

int func::input_max_num()
{
    std::cout << "최대 값을 입력해주세요(정수 양수만) : ";
    std::cin >> max_num_; 

    return max_num_;
}

void func::input_ary(int max_num)
{
    int cnt = 0;
    while (cnt == max_num)
    {
        decimal_num_ary_.push_back(cnt);
    }
}

int func::result_decimal_ary(int dedecimal_num_ary[])
{

}