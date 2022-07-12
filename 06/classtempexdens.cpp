#include <iostream>
#include <string>
using namespace std;

template <class T>
class Base
{
  T m;
};

class Son : public Base<int>
{
};

void test01()
{
  Son s1;
}

template <class T1, class T2>
class Son2 : public Base<T2>
{
  T1 obj;
};

void test02()
{
  Son2<int, int> S2;
}

int main()
{

  return 0;
}