#include <stdio.h>
#include <stdlib.h>
#include "queue_func.h"
#include <assert.h>

void initQueue(Queue *pq, int size)
{
    (*pq).pQueue = malloc(sizeof(int) * size);
    (*pq).size = size;
    (*pq).front = 0;
    (*pq).rear = 0;
}

void cleanupQueue(Queue *pq)
{
    free((*pq).pQueue); // 힙영역 초기화
}

void push(Queue *pq, int data)
{
    // 예외처리문 
    assert((*pq).rear != (*pq).size);

    (*pq).pQueue[(*pq).rear] = data;
    (*pq).rear++;

}
int pop(Queue *pq)
{
    // 예외처리문 
    assert((*pq).rear != (*pq).front); 
    
    int i = (*pq).front;
    (*pq).front++;

    return (*pq).pQueue[i];
}