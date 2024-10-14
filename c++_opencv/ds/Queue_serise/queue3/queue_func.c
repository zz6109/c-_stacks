#include <stdio.h>
#include <stdlib.h>
#include "queue_func.h"

void initQueue(Queue *pq)
{
    (*pq).front = 0;
    (*pq).rear = 0;
}

void push(Queue *pq, int data)
{
    // 예외처리문 
    if ((*pq).rear == QUEUESIZE)    // 입력된 값의 수가 100이면
    {
        fprintf(stderr, "스택 꽉 참\n");
        exit(1);
    }

    (*pq).Queue[(*pq).rear] = data;
    (*pq).rear++;

}
int pop(Queue *pq)
{
    // 예외처리문 
    if ((*pq).rear == (*pq).front)  // 입력된 것을 모두 출력했을때 둘다 0 이되기때문이다.
    {
        fprintf(stderr, "스택 비었음\n");
        exit(1);
    }
    
    int i = (*pq).front;
    (*pq).front++;

    return (*pq).Queue[i];
}