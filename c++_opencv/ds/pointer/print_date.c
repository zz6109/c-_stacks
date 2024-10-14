#include <stdio.h>
// 함수에서 인자를 포인터로 전달하는 경우 3
typedef struct 
{
    int year;
    int month;
    int day;
}Date;

// void printDate(Date d)   오버헤드를 방지하기 위해 포인터로 주소를 전달해주어야함
// {
//     printf("%d/%d/%d", d.year, d.month, d.day);
// }

void printDate(const Date *pd)  // 값이 변하지 않음
{
    printf("%d/%d/%d", (*pd).year, (*pd).month, (*pd).day); // .이 *보다 연산이 빨라서 괄호 쳐줘야함
}

int main(void)
{

    Date today = {2024, 8, 20};

    printDate(&today);  // 주소 전달
    return 0;
}