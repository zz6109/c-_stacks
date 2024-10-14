#include <stdio.h>
// 포인터와 배열
int main(void)
{
    int nums1[5] = {1,3,2,5,4};
    int nums2[5];

    // nums2 = nums1;  배열끼리는 치환이 안됨

    for (int i = 0; i < 5; i++)
    {
        printf("%d\t", nums1[i]);
        nums2[i] = nums1[i];

    }

    for (int i = 0; i < 5; i++)
    {
        printf("%d\t", nums2[i]);

    }

    return 0;
}