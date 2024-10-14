#ifndef STACK_H // 중복 전처리 방지
#define STACK_H
// #define STACSIZE 100

typedef struct  // typedef를 해주는 이유는 struct를 안써주기 위해서
{
    // int ary[STACSIZE];
    int *pArr;
    int size;
    int tos;
}Stack;

void initStack(Stack *ps, int size);


void push(Stack *ps,int data);
int pop(Stack *ps);
void cleanupStack(Stack *ps);

#endif