#include <stdio.h>
#include <stdlib.h>
// 포인터와 배열

int main(void)
{
    int size, i;
    scanf("%d", &size);

    // int ary[size];
    int *ary = malloc(sizeof(int) * size);  // c99 이전 컴파일러는 malloc을 사용해야만 가변 길이 배열을 사용할수 있었다.
    for (i = 0; i < size; i++)  // 사이즈 까지 배열 생성
    {
        ary[i] = i + 1;
    }

    for (i = 0; i < size; i++)  // 사이즈까지 1씩 더한 값을 저장
    {  
        printf("%d\n", ary[i]);
    }
    return 0;
}