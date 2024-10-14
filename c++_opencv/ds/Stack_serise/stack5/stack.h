#ifndef STACK_H // 중복 전처리 방지
#define STACK_H
// #define STACSIZE 100

typedef struct  // typedef를 해주는 이유는 struct를 안써주기 위해서
{
    // int *pArr;
    void *pArr;
    int eleSize;
    int size;
    int tos;
}Stack;

void initStack(Stack *ps, int size, int eleSize);
void cleanupStack(Stack *ps);

void push(Stack *ps, const void *pData);
void pop(Stack *ps, void *pResult);
// void push(Stack *ps,int data);
// int pop(Stack *ps, int *pResult);


#endif  