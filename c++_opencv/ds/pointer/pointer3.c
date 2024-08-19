#include <stdio.h>
// 캐스팅후 포인팅
int main(void)
{
    int a = 0x12345678;
    // int *p;

    // p = &a;

    char *p;
    p = (char *)&a; // 리틀엔디언 시스템

    printf("*p: %x\n", *p);

    return 0;
}