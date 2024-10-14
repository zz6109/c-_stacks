#include "gcd.h"
#include <stdio.h>

int main(void)
{
    int n1, n2;
    printf("두 숫자 입력 : ");
    scanf("%d%d", &n1, &n2);

    printf("두 숫자 %d, %d의 최대 공약수는 %d입니다.", n1, n2, gcd(n1,n2));
}