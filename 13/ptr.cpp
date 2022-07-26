#include <memory>
#include <iostream>
using namespace std;

void test01()
{
  shared_ptr<int> p = make_shared<int>(42);
  int q = 10;
  cout << *p << endl;
  p = &q;
   
}

int main()
{
  test01();
  return 0;
}

