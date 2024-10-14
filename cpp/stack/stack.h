#ifndef STACK_H // 중복 전처리 방지
#define STACK_H
// #define STACSIZE 100

class Stack // cpp에선 typedef 안해도 됨, structer가 class로 바뀜
{
private:    // static으로 만듬
    int *pArr;
    int size;
    int tos;

public:
    // 멤버 함수로 전환
    Stack(int size);   // 생성자로 전환(constructor)
    // 반환값이없다, 구조체의 이름을 쓴다.
    ~Stack();        // 소멸자로 전환(destructor)
    // 반환값이 없다, 틸터를 붙인다, 구조체의 이름을 쓴다.

    void push(int data);
    int pop();
};

#endif