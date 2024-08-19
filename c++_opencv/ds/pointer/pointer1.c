#include <stdio.h>
// 포인터
int main(void)
{
    int a;
    int *p;

    a = 100;
    p = &a;
    *p = 200;

    printf("a: %d\n", a);
    printf("p: %u\n", p);
}