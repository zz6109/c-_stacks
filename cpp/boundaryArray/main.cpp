#include <iostream>
#include "boundaryArray.h"
#include "complex.h"

int main()
{
    BoundaryArray<int> arr3;
    BoundaryArray<int> arr4(10);
    int nums[] = {1, 2, 3, 4, 5};
    BoundaryArray<int> arr5(nums, 5, 1);
    BoundaryArray<int> arr6 = arr5;

    arr3 = arr5;

    if (arr3 == arr5)
    {
        std::cout << "arr3 == arr5" << std::endl;
    }
    else
    {
        std::cout << "arr3 != arr5" << std::endl;
    }
    
    

    BoundaryArray<int> arr1(1, 5);
    for (int i = arr1.lower(); i < arr1.upper()+1; i++)
    {
        arr1[i] = i;
    }
    
    for (int i = arr1.lower(); i < arr1.upper()+1; i++)
    {
        std::cout << arr1[i] << std::endl;
    }

    BoundaryArray<Complex> arr2(11, 16);

    return 0;
}