#include <stdio.h>
// void포인터
// 포인터의 자료형이 정해지지 않은 타입
// 특정자료형으로 캐스팅후 사용하여야함
// 순수하게 주소만 저장한다면 바로 사용가능
int main(void)
{
  int a = 100;
  double d = 3.14;

  void *p;
  p = &a;
  *(int *)p = 200;

  p = &d;
  *(double *)p = 2.718;

  printf("a : %d\n", a);
  printf("d : %f\n", d);
  return 0;
}