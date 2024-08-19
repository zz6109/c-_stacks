#ifndef STACK_H // 중복 전처리 방지
#define STACK_H
#define STACSIZE 100

typedef struct  // typedef를 해주는 이유는 struct를 안써주기 위해서
{
    int ary[STACSIZE];
    int tos;
}Stack;

void initStack(Stack *ps);

// void push(Stack s,int data);
// int pop(Stack s);

void push(Stack *ps,int data);
int pop(Stack *ps);

#endif