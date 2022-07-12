#include <iostream>
#include <string>
using namespace std;

class Person1
{
public:
  void showPerson1()
  {
    cout << "Person1 show" << endl;
  }
};

class Person2
{
public:
  void showPerson2()
  {
    cout << "Person2 show" << endl;
  }
};

template <class T>
class MyClass
{
public:
  T obj;
  void func1()
  {
    obj.showPerson2();
  }

  void func2()
  {
    obj.showPerson2();
  }
};

void test01()
{
  MyClass<Person2> m;
  m.func1();
}

int main()
{
  test01();
  return 0;
}