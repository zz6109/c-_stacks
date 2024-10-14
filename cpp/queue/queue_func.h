#ifndef Queue_H
#define Queue_H

class Queue
{
private:
    int *pQueue;
    int size;
    int front;
    int rear;
    
public:
    Queue(int size);       // 생성자
    ~Queue();              // 소멸자  

    void push(int data); // 구조체에 값 입력
    int pop();             // 구조체에 값 출력

    
};



#endif