#include <stdio.h>
#define STACSIZE 100

int stack[STACSIZE];
int tos;                // top of stack

void push(int data)
{
    stack[tos] = data;
    ++tos;
}

int pop(void)
{
    --tos;
    
  //int re;
  //re = stack[tos];
  //return re;
  
    return stack[tos];
}

int main(void)
{   
    push(100);
    push(200);
    push(300);
    
    int re = pop();     // 맨 뒤의 값 출력
    printf("1st pop() : %d\n", re);
    
    printf("2st pop() : %d\n", pop());      // 2번째 저장값 출력
    
    printf("3st pop() : %d\n", pop());      // 1번째 저장값 출력
    return 0;
}

