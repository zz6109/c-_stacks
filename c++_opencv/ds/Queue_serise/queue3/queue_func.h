#ifndef Queue_H
#define Queue_H
#define QUEUESIZE 100

typedef struct 
{
    int Queue[QUEUESIZE];
    int front;
    int rear;
}Queue;

void initQueue(Queue *pq);      // 구조체 초깃값 초기화

void push(Queue *pq, int data); // 구조체에 값 입력
int pop(Queue *pq);             // 구조체에 값 출력

#endif