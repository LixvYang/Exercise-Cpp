#include <iostream>
#include <string>
using namespace std;

template <class T1, class T2>
class Person
{
public:
  Person(T1 nama, T2 age);
  // {
  //   this->m_Name = name;
  //   this->m_Age = age;
  // }

  T1 m_Name;
  T2 m_Age;
};

template <typename T1, typename T2>
Person<T1, T2>::Person(T1 nama, T2 age)
{
  this->m_Name = name;
  this->m_Age = age;
}

int main()
{

  return 0;
}
