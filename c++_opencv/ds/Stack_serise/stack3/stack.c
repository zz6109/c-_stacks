#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

void initStack(Stack *ps)
{
    (*ps).tos = 0;
}

void push(Stack *ps,int data)
{
    // stack[tos] = data;
    // ++tos;

    // s.ary[s.tos] = data;
    // ++s.tos;
    if (ps->tos == STACSIZE)    // 예외처리문 배열의 요소가 배열의 최대 요소수에 도달하면 프로그램 종료
    {
        fprintf(stdout, "스택 꽉 참\n");
        exit(1);
    }
    

    (*ps).ary[ps->tos] = data;
    ++(*ps).tos;

}

int pop(Stack *ps)
{
    // --tos;  
    // return stack[tos];

    // --s.tos;
    // return s.ary[s.tos];
    if (ps->tos == 0)       // 예외처리문 배열의 요소가 들어 있지 않음
    {
        fprintf(stdout, "스택 비었음\n");
        exit(1);
    }
    

    --ps->tos;
    return ps->ary[ps->tos];
}
