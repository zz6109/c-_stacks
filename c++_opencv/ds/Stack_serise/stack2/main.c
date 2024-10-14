#include <stdio.h>  // 함수선언만 존재(헤더파일), 라이브러리는 오브젝트 파일로 존재
#include "stack.h"

int main(void)
{   
    push(100);
    push(200);
    push(300);
    
    int re = pop();
    printf("1st pop() : %d\n", re);
    
    printf("2st pop() : %d\n", pop());
    
    printf("3st pop() : %d\n", pop());
    return 0;
}



