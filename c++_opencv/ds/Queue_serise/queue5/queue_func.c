#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue_func.h"
#include <assert.h>

void initQueue(Queue *pq, int size, int eleSize)
{
    (*pq).pQueue = malloc(eleSize * size);

    assert((*pq).pQueue /*!= NULL*/);   // 0이 아니다는 생략가능하다.
   
    (*pq).eleSize = eleSize;
    (*pq).size = size;
    (*pq).front = 0;
    (*pq).rear = 0;
}

void cleanupQueue(Queue *pq)
{
    free((*pq).pQueue); // 힙영역 초기화
}

void push(Queue *pq, const void *pData)
{
    // 예외처리문 
    assert((*pq).front != (*pq).size);

    // (*pq).pQueue[(*pq).rear] = pData;   
    // void 포인터는 인자로 전달 할수 없음
    memcpy((unsigned char *)pq->pQueue + ((*pq).eleSize * (*pq).rear), pData, (*pq).eleSize);
    // void 포인터를 unsigned char로 캐스팅
    //pQeue 배열의 인덱스에 pDate의 입력값을 eleSize 자료형의 바이트수 만큼 복사해서 저장
    (*pq).rear++;

}
void pop(Queue *pq, void *pResult)
{
    // 예외처리문 
    assert((*pq).rear != (*pq).front); 
    
    memcpy(pResult, (unsigned char *)pq->pQueue + ((*pq).eleSize * (*pq).front), (*pq).eleSize);
    // pQueue 배열에 저장된 값을 pResult에 eleSize 바이트수 만큼 복사
    // 반환값이 없기 때문에 메모리에 직접 저장
    // return (*pq).pQueue[i];  void 포인터는 반환값이 없다.
    (*pq).front++;
}