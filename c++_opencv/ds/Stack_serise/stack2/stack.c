#define STACSIZE 100

static int stack[STACSIZE];     // static 전역 변수를 사용하면 메인 함수에서 변수에 접근할 수 없다.(허용된 연산을 통해서 변수에 접근하게 한다.)
static int tos;                 // top of stack

void push(int data)
{
    stack[tos] = data;
    ++tos;
}

int pop(void)
{
    --tos;
  
    return stack[tos];
}