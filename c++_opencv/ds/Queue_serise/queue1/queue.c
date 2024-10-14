#include <stdio.h>
// 전역 변수는 0으로 초기화 됨
int queue[100];
int front;
int rear;

void push(int data)
{
    queue[rear] = data;
    ++rear;
}
int pop(void)
{
    int i = front;
    ++front;
    return queue[i];
}
int main(void)
{
    push(100);
    push(200);

    printf("1st pop() : %d\n", pop());

    push(300);

    printf("2st pop() : %d\n", pop());
    printf("3st pop() : %d\n", pop());
}