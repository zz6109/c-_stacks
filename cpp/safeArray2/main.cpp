#include "safearray.h"
#include <iostream>
int main()
{
    SafeArray arr1;
    SafeArray arr2(10);

    int nums[] = {1, 2, 3, 4, 5};
    SafeArray arr3(nums, 5);

    const SafeArray arr4 = arr3;

    arr1 = arr3;

    if (arr1 == arr3)
    {
        std::cout << "arr1 == arr3" << std::endl;
    }
    else
    {
        std::cout << "arr1 != arr3" << std::endl;
    }
    
    for (int i = 0; i < arr1.size(); i++)
    {
        std::cout << arr1[i] << " ";
    }
    std::cout << std :: endl;

    for (int i = 0; i < arr4.size(); i++)
    {
        std::cout << arr4[i] << " ";
    }
    std::cout << std :: endl;
    
    // arr1[-1] = 1; // 바운더리 벗어남

    return 0;
}