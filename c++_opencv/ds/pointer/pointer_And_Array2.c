#include <stdio.h>
// 포인터와 배열2
int main(void)
{
    int nums[5] = {1,3,2,5,4};
    int *p;

    p = nums;

    // 배열식
    for (int i = 0; i < 5; i++)
    {
        printf("nums[%d] : %d\n", i, nums[i]); // nums[i] = p[i]
    }
    
    printf("\n");

    for (int i = 0; i < 5; i++)
    {
        printf("p[%d] : %d\n", i, p[i]);
    }
    
    printf("\n");
    
    // 포인터
    for (int i = 0; i < 5; i++)
    {
        printf("*(nums+%d) : %d\n", i, *(nums+i));  // *(nums+i) = *(p+i) | *(+i) = [i]
    }
    
    printf("\n");

    for (int i = 0; i < 5; i++)
    {
        printf("*(p+%d) : %d\n", i, *(p+i));
    }
    
    printf("\n");

    return 0;
}