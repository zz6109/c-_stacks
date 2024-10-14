#include <iostream>
// using으로 선언 해주면 std를 안붙이고 함수만 쓸수 있다.
using std::cout;
using std::endl;
using std::cin;
using std::string;

int main()
{
    // :: scope resolution operator
    cout << "입력 : ";
    // 식의 결과 값 : cout, 부효과 : "입력" 화면상에 출력

    string value;
    cin >> value;

    cout << "입력값 : " << value << std::endl;
    return 0;
}