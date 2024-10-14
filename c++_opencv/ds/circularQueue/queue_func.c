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
    // assert((*pq).rear != (*pq).size);
    // 입력 후 출력을 하면 10 만큼의 자리가 비어있는 상태로 20까지 저장이 되기때문에 10이라는 공간을 다시 사용해주어야 한다
    assert(((*pq).rear + 1) % (*pq).size != (*pq).front);
    // rear와 front가 겹치는 순간이 발생하는 것을 방지
    // 하나를 덜쓰고 그 값과 비교

    (*pq).pQueue[(*pq).rear] = data;
    // (*pq).rear++;
    (*pq).rear = ((*pq).rear + 1) % (*pq).size;
    // 항상 1부터 10까지 저장 되게끔 위치 조정
}
int pop(Queue *pq)
{
    // 예외처리문 
    assert((*pq).rear != (*pq).front);  
    
    
    int i = (*pq).front;
    // (*pq).front++;
    (*pq).front = ((*pq).front + 1) % (*pq).size;

    return (*pq).pQueue[i];
}