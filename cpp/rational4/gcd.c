#include "gcd.h"
int gcd(int a, int b)
{
    int remain;
    while (remain = a % b)
    {
        a = b;
        b = remain;
    }
    
    return b;
}
// int gcd(int a, int b)
// {
//     if (b > a)
//     {
//         int tmp = a;
//         a = b;
//         b = tmp;
//     }
    
//     result = 1;
//     for (int i = 0; i <= b; i++)
//     {
//         if (a % i == 0 && b % i == 0)
//         {
//             result = i;
//         } 
//     }
    
//     return result;
// }