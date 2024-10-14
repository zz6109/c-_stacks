#include "array.h"
#include "complex.h"
#include <iostream>
int main()
{
    int nums1[] = {1, 2, 3, 4, 5};
    Array<int> arr1(nums, 5);

    for (int i = 0; i < 5; i++)
    {
        std::cout << arr1[i] << std::endl;
    }
    
    double num2[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    Array<double> arr2(nums2, 5);

    for (int i = 0; i < 5; i++)
    {
        std::cout << arr2[i] << std::endl;
    }

    Complex num3[] = { Complex(3.0, 40), Complex(), Complex(3.0)};
    Array<Complex> arr3(num3, 3);

    for (int i = 0; i < 5; i++)
    {
        std::cout << arr3[i] << std::endl;
    }

    return 0;
}