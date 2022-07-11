#include <iostream>
using namespace std;
template <typename T>
void mySwap(T & a, T & b)
{
  T temp = a;
  a = b;
  b = temp;
}

void swapInt(int & a, int & b)
{
  int temp = a;
  a = b;
  b = temp;
}


void swapDouble(double & a, double & b)
{
  double temp = a;
  a = b;
  b = temp;
}

void test01()
{
  double a = 1.02;
  double b = 2.10;

  mySwap<double>(a, b);
  cout << "a =  " << a << endl;
  cout << "b =  " << b << endl;
}

int main()
{
  test01();
  return 0;
}
