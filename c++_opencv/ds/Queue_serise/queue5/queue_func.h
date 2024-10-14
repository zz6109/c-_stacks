#ifndef Queue_H
#define Queue_H

typedef struct 
{
    void *pQueue;    // 배열
    int eleSize;    // 자료형 구분
    int size;       // 요소수 가변
    int front;
    int rear;
}Queue;

void initQueue(Queue *pq, int size, int eleSize);      // 구조체 초깃값 초기화
// 배열 구조체, 배열의 요소수(가변), 자료형 바이트 수
void cleanupQueue(Queue *pq);   // 힙영역 초기화

void push(Queue *pq, const void *pData); // 구조체에 값 입력
// 배열 구조체, 입력값(주소)
void pop(Queue *pq, void *pResult);             // 구조체에 값 출력, 자료형 구분 없이(int, double)
// 배열 구조체, 출력값(주소)

#endif