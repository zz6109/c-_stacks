#include "queue_func.h"
#include <cassert>
#include <iostream>

Queue::Queue(int size)
{
    // (*this).pQueue = (int*)malloc(sizeof(int) * size);
    this->pQueue = new int[size];
    assert(this->pQueue );
    (*this).size = size;
    (*this).front = 0;
    (*this).rear = 0;
}

Queue::~Queue()
{
    // free((*this).pQueue);
    delete [] this->pQueue;
}

void Queue::push(int data)
{
    // 예외처리문 
    assert((*this).rear != (*this).size);

    (*this).pQueue[(*this).rear] = data;
    (*this).rear++;

}
int Queue::pop()
{
    // 예외처리문 
    assert((*this).rear != (*this).front); 
    
    int i = (*this).front;
    (*this).front++;

    return (*this).pQueue[i];
}