#include <stdio.h>
// 캐스팅후 포인팅
int main(void)
{
    int a = 0x12345678;
    // int *p;

    // p = &a;

    char *p;
    p = (char *)&a; // 기본적으로 리틀엔디언 시스템임, 빅엔디언으로 바꿔 줄려면 a를 역으로 배열시키는 함수를 만들어야함.(하지마)

    short *p_s;
    p_s = (short *)&a;

    printf("char *p: %x\n", *p);
    printf("short *p: %x\n", *p_s);

    return 0;
}