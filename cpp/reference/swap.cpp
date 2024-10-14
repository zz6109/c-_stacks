#include <iostream>
using std::cout;
using std::endl;

// 연산자 중복때문에 reference를 써야한다.

void swap(int &ra, int &rb)
{
    int tmp = ra;
    ra = rb;
    rb = tmp;
}

int main()
{
    int a, b;
    a = 100;
    b = 200;

    swap(a,b);

    cout << "a : " << a << "\t" << "b : " << b << endl;


}