typedef struct  // typedef를 해주는 이유는 struct를 안써주기 위해서
{
    int ary[100];
    int tos;
}Stack;

void initStack(Stack *ps)
{
    (*ps).tos = 0;
}

void push(Stack *ps,int data)
{
    // stack[tos] = data;
    // ++tos;

    // s.ary[s.tos] = data;
    // ++s.tos;

    (*ps).ary[ps->tos] = data;
    ++(*ps).tos;

}

int pop(Stack *ps)
{
    // --tos;  
    // return stack[tos];

    // --s.tos;
    // return s.ary[s.tos];

    --ps->tos;
    return ps->ary[ps->tos];
}
