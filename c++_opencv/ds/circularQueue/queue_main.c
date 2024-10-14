// 가변 길이의 배열 

#include <stdio.h>
#include "queue_func.h"

int main(void)
{
    Queue q1, q2;

    initQueue(&q1, 10);     // 10 : 배열 최대 요소수 설정
    initQueue(&q2, 100);

    push(&q1, 100);
    push(&q1, 200);
    push(&q1, 300);

    printf("1st pop() : %d\n", pop(&q1));
    printf("2st pop() : %d\n", pop(&q1));
    printf("3st pop() : %d\n", pop(&q1));


    push(&q2, 400);
    push(&q2, 500);
    push(&q2, 600);

    printf("1st pop() : %d\n", pop(&q2));
    printf("2st pop() : %d\n", pop(&q2));
    printf("3st pop() : %d\n", pop(&q2));

    cleanupQueue(&q1);
    cleanupQueue(&q2);

    return 0;
}