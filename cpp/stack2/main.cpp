#include "stack.h"
#include <iostream>

int main()
{
    Stack s1;
    Stack s2(20);

    // Stack s3 = s2;   

    // s1 = s2;

    s1.push(100);
    s1.push(200);
    s1.push(300);

    std::cout << "s1 1st pop() : " << s1.pop() << std::endl;
    std::cout << "s1 2st pop() : " << s1.pop() << std::endl;
    std::cout << "s1 3st pop() : " << s1.pop() << std::endl;
    
    for (int i = 1; i < 11; i++)
    {
        if (!s2.isFull())
        {
            s2.push(i);
        }
        
    }
    
    while (!s2.isEmpty())
    {
        std::cout << s2.pop() << std::endl;
    }
    

    return 0;
}