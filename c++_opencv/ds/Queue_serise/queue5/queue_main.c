// generic 
#include "queue_func.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int main(void)
{
    Queue q1, q2;

    initQueue(&q1, 10, sizeof(int));     // 10 : 배열 최대 요소수 설정
    initQueue(&q2, 100, sizeof(double));

    int i;
    i = 100; push(&q1, &i); // 시작 주소와 크기
    i = 200; push(&q1, &i);
    i = 300; push(&q1, &i);

    int re1;
    pop(&q1, &re1);     printf("s1 1st pop() : %d\n", re1);
    pop(&q1, &re1);     printf("s1 2st pop() : %d\n", re1);
    pop(&q1, &re1);     printf("s1 3st pop() : %d\n", re1);

    double d;
    d = 1.1;    push(&q2, &d);
    d = 2.2;    push(&q2, &d);
    d = 3.3;    push(&q2, &d);

    double re2;
    pop(&q2, &re2);     printf("s2 1st pop() : %f\n", re2);
    pop(&q2, &re2);     printf("s2 2st pop() : %f\n", re2);
    pop(&q2, &re2);     printf("s2 3st pop() : %f\n", re2);

    cleanupQueue(&q1);
    cleanupQueue(&q2);

    return 0;
}