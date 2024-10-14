#include <stdio.h>
// 포인터와 배열
int main(void)
{
    int nums1[5] = {1,3,2,5,4};
    int nums2[5] = {1,3,2,5,4};

    // if (nums1 == nums2)  주소끼리 비교한것이기 때문에 같지 않다.
    // {
    //     printf("nums1과 nums2는 같다.");
    // }
    // else
    // {
    //     printf("nums1과 nums2는 같지않다.");
    // }
    int i;

    for (i = 0; i < 5; i++)
    {
        if (nums1[i] != nums2[i])   // 두 배열이 다르면 브레이크
        {
            break;
        }
        
    }
    
    if (i == 5) // 두배열이 모두 같으면 for문이 다 돌아가서 i가 5가 된다.
    {
        printf("nums1과 nums2는 같다.");
    }
    else
    {
        printf("nums1과 nums2는 같지않다.");
    }
    return 0;
}