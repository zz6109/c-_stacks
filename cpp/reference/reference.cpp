#include <iostream>
using std::cout;
using std::endl;

int main()
{
    int a = 100;
    int &ra = a;

    ra = 200;

    cout << "a : " << a << endl;

}