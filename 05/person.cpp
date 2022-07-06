#include <iostream>
using namespace std;

class Person
{
  public:
  Person()
  {
    cout << "Person的构造函数调用" << endl;
  }
  
  Person(int a)
  {
    cout << "Person have params" << endl;
  }
  Person( const Person &p )
  {
    age = p.age;
  }
  ~Person()
  {
    cout << "Person的析构函数调用" << endl;
  }

  int age;


};

void test01(){
  Person p;
  Person p2(10);
  Person p3(10);

  cout << "p2 age is" << p2.age << endl;
  cout << "p3 age is" << p3.age << endl;

}

int main()
{
  // 1. 括号法 
  test01();
  
  return 0;
}

