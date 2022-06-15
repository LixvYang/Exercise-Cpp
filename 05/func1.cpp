#include<iostream>

void reset(int *ip)
{
  *ip = 0;
  ip = 0;
}

int main() {
  int i = 42;
  int &ref = i;
  std::cout << &i << std::endl;
  std::cout << &ref << std::endl;
  reset(&i);
  std::cout << i << std::endl;
  return 0;
}