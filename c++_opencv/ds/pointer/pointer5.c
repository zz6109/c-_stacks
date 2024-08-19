#include <stdio.h>
// 함수 포인터

int add(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}

int main(void)
{
    int (*fp)(int, int);

    int re;

    fp = &add;
    re = (*fp)(4,3);
    printf("re: %d\n", re);

    fp = &sub;
    re = (*fp)(4,3);
    printf("re: %d\n", re);

    return 0;
}