// 복수 큐

#include <stdio.h>
#include "queue_func.h"

int main(void)
{
    Queue q1, q2;

    initQueue(&q1);
    initQueue(&q2);

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

    return 0;
}