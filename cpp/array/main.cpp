#include "array.h"
#include <iostream>
int main()
{
    Array arr1;
    Array arr2(10);

    int nums[] = {1, 2, 3, 4, 5};
    Array arr3(nums, 5);

    Array arr4 = arr3;

    arr1 = arr3;

    if (arr1 == arr3)
    {
        std::cout << "arr1 == arr3" << std::endl;
    }
    else
    {
        std::cout << "arr1 != arr3" << std::endl;
    }
    
    for (int i = 0; i < arr1.size_; i++)
    {
        
    }
    
    

    return 0;
}