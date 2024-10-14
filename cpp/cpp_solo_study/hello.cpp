#include <iostream>
// 연산자 중복 << 가 비트연산자로 쓰인것이 아니라 printf로 사용됨
int main()
{
    //std::cout << "안녕";
    // 위 코드를 컴파일러가 밑 코드로 변환해서 실행시킨다.
    operator<<(std::cout, "안녕");
    // std::cout.operator<<("안녕");

    // std::cout << std::endl;
    // 위 코드를 컴파일러가 밑 코드로 변환해서 실행시킨다.
    // operator<<(std::cout, std::endl);
    // 위 코드를 컴파일러가 밑 코드로 변환해서 실행시킨다.
    std::cout.operator<<(std::endl);

    //std::cout << "hello, world" << std::endl;
    // 위 코드를 컴파일러가 밑 코드로 변환해서 실행시킨다.
    operator<<(std::cout, "안녕").operator<<(std::endl);


    return 0;
}