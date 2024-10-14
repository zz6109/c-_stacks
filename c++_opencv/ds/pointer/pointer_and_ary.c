#include <stdio.h>
// 포인터와 배열
int main(void)
{
    int nums[5] = {1,3,2,5,4};
    int *p;

    p = nums;

    printf("*p : %d\n", *p);

    ++p;

    printf("*p : %d\n", *p);

    return 0;
}