#include <iostream>
using namespace std;

int* func()
{
  // new
  int* p = new int(10);
  return p;
}

int main()
{
  int* p = func();

  cout << *p << endl;
  cout << &p << endl;
  delete p;
  cout << *p << endl;
  return 0;
}
