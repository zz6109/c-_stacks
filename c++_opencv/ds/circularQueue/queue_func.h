#ifndef Queue_H
#define Queue_H

typedef struct 
{
    int *pQueue;
    int size;
    int front;
    int rear;
}Queue;

void initQueue(Queue *pq, int size);      // 구조체 초깃값 초기화, 사이즈의 값

void push(Queue *pq, int data); // 구조체에 값 입력
int pop(Queue *pq);             // 구조체에 값 출력

void cleanupQueue(Queue *pq);   // 힙영역 초기화

#endif