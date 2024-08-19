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
  
    return stack[tos];
}