// 분할 컴파일

#include <stdio.h>
#include "queue_func.h"

int main(void)
{
    push(100);
    push(200);
    push(300);

    printf("1st pop() : %d\n", pop());
    printf("1st pop() : %d\n", pop());
    printf("1st pop() : %d\n", pop());

    return 0;
}