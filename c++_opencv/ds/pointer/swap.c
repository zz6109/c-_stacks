#include <stdio.h>
// 포인터와 배열
// 호출하는 쪽의 변수 값을 호출당하는 쪽에서 바꿔줘야하는 상황
// 함수에서 인자를 포인터로 전달하는 경우 1
int swap(int *pa, int *pb);

int main(void)
{
    int a,b;
    a= 100;
    b= 200;

    printf("a, b : %d, %d\n", a, b);

    swap(&a, &b);

    
    printf("a, b : %d, %d\n", a, b);

    return 0;
}

int swap(int *pa, int *pb)
{
    int temp;
    temp = *pa;
    *pa = *pb;
    *pb = temp;

    return *pa, *pb;
}