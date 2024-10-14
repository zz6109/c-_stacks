#include "employee.h"

int main()
{
    const Employee e1(1, "윤석열", NULL);
    const Employee e2(2, "한동훈", &e1);
    const Employee e3(3, "김건희", &e1);
    const Employee e4(4, "홍준표", &e3);
    const Employee e5(5, "이준석", &e3);
    const Employee e6(6, "안철수", &e3);

    // Employee e; X    명시적인 생성자가 있기때문에 실행불가-Employee(int id, String name, const Employee *p);
    // Employee e7 = c1; X
    // e1 = e2; X

    std::cout << e1 << std::endl;
    std::cout << e2 << std::endl;
    std::cout << e3 << std::endl;
    std::cout << e4 << std::endl;
    std::cout << e5;
    std::cout << e6;

    return 0;
}