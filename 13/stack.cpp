#include <iostream>
using namespace std;

int* test01()
{
  int a = 10; // 存放在栈区,栈区的数据在执行完后自动释放
  return &a; 
}

int main()
{
  int* p = test01(); 
  cout << *p << endl;
  cout << *p << endl;
  return 0;
}

