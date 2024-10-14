#include <stdio.h>
// 배열의 합 
int sum_ary(const int *pary, int size)    // 포인터가 가리키는 대상이 바뀌지 않음
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += pary[i]; // *(parr + i)
    }
    
    return sum;
}

int main(void)
{
    int nums[10] = {1,3,2,5,4, 7, 8, 10, 23, 29};

    int sum = sum_ary(nums, 10);
    // int sum = sum_ary(nums+5, 5); 5번째 자리부터 10까지 5개 요소의 합
    printf("sum : %d\n", sum);

    return 0;
}