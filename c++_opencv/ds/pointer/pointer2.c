#include <stdio.h>
// 포인터는 반드시 대상을 가리키고 역참조해야한다.
int main(void)
{
    // int *p;
    // *p = 200;

    int num;
    int nums[5] = {1, 2, 3, 4, 5};

    int *p;
    p = &num;
    *p = 100;

    p = &nums[1];
    *p = 7;

    printf("num: %d\n", num);
    printf("nums: ");

    for (int i = 0; i < 5; ++i)
    {
        printf("%2d", nums[i]);
    }
    printf("\n");

    return 0;
}