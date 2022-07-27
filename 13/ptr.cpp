#include <memory>
#include <iostream>
using namespace std;

void test01()
{
  // 
  int* p = new int(10);
  cout << *p << endl;
  cout << p << endl;
  delete p;
  long i = 0;
  long *q = &i;
  cout << sizeof(i) << endl;
  cout << sizeof(*q) << endl;

}

int main()
{
  test01();
  return 0;
}

