#ifndef FUNC_H
#define FUNC_H
#include <vector>

class func
{
private:
    int max_num_;            // 숫자 몇까지 출력할지
    std::vector<int>decimal_num_ary_;  // 계산후 저장되는 소수의 배열
public:
    func(int max_num = 0, int decimal_num_ary[]);   // 배열을 멤버변수로 받을려면 다른 방법을 써야함
    // ~func();
    // max_num을 입력받을 함수
    int input_max_num();
    // 0부터 max_num까지 나열할 함수(decimal_num_ary에 임시로 저장)
    void input_ary(int max_num);
    // 소수의 배열을 넣을 함수(decimal_num_ary에 들어있는 변수를 소수로 분류하여 다시 저장)
    int result_decimal_ary(int dedecimal_num_ary[]);



};

#endif