#include "stack.h"
// #include <cstdio>        printf 없음
// #include <stdlib.h>      malloc 안써도 돼서 주석처리
#include <cassert>

Stack::Stack(int size)
{
    // this->pArr = (int *)malloc(sizeof(int) * size);
    this->pArr = new int[size]; // malloc 대체(c++)
    assert(this->pArr );
    this->size = size;
    this->tos = 0;
}

Stack::~Stack()
{
    delete [] this->pArr;   // free 대체(c++)
}

void Stack::push(int data)
{
    // if (ps->tos == ps->size)
    // {
    //     fprintf(stdout, "스택 꽉 참\n");
    //     exit(1);
    // }
    
    assert(this->tos != this->size);    // 예외처리문 : 배열의 요소가 배열의 최대 요소수에 도달하면 프로그램 종료

    (*this).pArr[this->tos] = data;
    ++(*this).tos;

}

int Stack::pop()
{
    // if (ps->tos == 0)
    // {
    //     fprintf(stdout, "스택 비었음\n");
    //     exit(1);
    // }

    assert(this->tos != 0);  // 예외처리문 : 배열의 요소가 들어 있지 않음
    
    --this->tos;
    return this->pArr[this->tos];
}
