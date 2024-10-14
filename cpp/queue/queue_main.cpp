// 가변 길이의 배열 
#include "queue_func.h"
#include <iostream>

int main(void)
{
    Queue q1(10), q2(100);

    // q1.initQueue(10);     // 10 : 배열 최대 요소수 설정
    // q2.initQueue(100);

    q1.push(100);
    q1.push(200);
    q1.push(300);

    // printf("1st pop() : %d\n", q1.pop());
    std::cout << "1st pop() : " << q1.pop() << std::endl;
    std::cout << "2st pop() : " << q1.pop() << std::endl;
    std::cout << "2st pop() : " << q1.pop() << std::endl;



    q2.push(400);
    q2.push(500);
    q2.push(600);

    std::cout << "1st pop() : " << q2.pop() << std::endl;
    std::cout << "2st pop() : " << q2.pop() << std::endl;
    std::cout << "3st pop() : " << q2.pop() << std::endl;

    // q1.cleanupQueue();
    // q2.cleanupQueue();

    return 0;
}