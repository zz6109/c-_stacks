#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void initStack(Stack *ps, int size)
{
    ps->pArr = malloc(sizeof(int) * size);
    ps->size = size;
    ps->tos = 0;
}

void cleanupStack(Stack *ps)
{
    free(ps->pArr);
}

void push(Stack *ps,int data)
{
    // if (ps->tos == ps->size)
    // {
    //     fprintf(stdout, "스택 꽉 참\n");
    //     exit(1);
    // }
    
    assert(ps->tos != ps->size);    // 예외처리문 : 배열의 요소가 배열의 최대 요소수에 도달하면 프로그램 종료

    (*ps).pArr[ps->tos] = data;
    ++(*ps).tos;

}

int pop(Stack *ps)
{
    // if (ps->tos == 0)
    // {
    //     fprintf(stdout, "스택 비었음\n");
    //     exit(1);
    // }

    assert(ps->tos != 0);  // 예외처리문 : 배열의 요소가 들어 있지 않음
    
    --ps->tos;
    return ps->pArr[ps->tos];
}
