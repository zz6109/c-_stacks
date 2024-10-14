#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void initStack(Stack *ps, int size, int eleSize)
{
    // ps->pArr = malloc(sizeof(int) * size);
    ps->pArr = malloc(eleSize * size);
    assert(ps->pArr /*!= NULL*/);   // 0이 아니다는 생략가능하다.

    ps->eleSize =eleSize;
    ps->size = size;
    ps->tos = 0;
}    // int *pArr;

void cleanupStack(Stack *ps)
{
    free(ps->pArr);
}

void push(Stack *ps, const void *pData) // 입력받는 값의 자료형은 수정되면 안되기때문에 const 붙여줌
{
    assert(ps->tos != ps->size);    // 예외처리문 : 배열의 요소가 배열의 최대 요소수에 도달하면 프로그램 종료

    // (*ps).pArr[ps->tos] = data;
    // memcpy(&ps->pArr[ps->tos], pData, ps->eleSize);
    memcpy((unsigned char *)ps->pArr + ps->eleSize * ps->tos, pData, ps->eleSize);
    // (*ps).eleSize 자료형의 바이트 수 만큼, pData 주솟값을 (*ps).tos 배열의 [(*ps).eleSize * (*ps).tos] 요소 자리에 복사
    ++(*ps).tos;

}

void pop(Stack *ps, void *pResult)
{
    assert(ps->tos != 0);

    --ps->tos;

    // *pResult = ps->pArr[ps->tos];   // return을 안쓰고 값 저장

    memcpy(pResult, (unsigned char *)ps->pArr + ps->eleSize * ps->tos, ps->eleSize);
}
