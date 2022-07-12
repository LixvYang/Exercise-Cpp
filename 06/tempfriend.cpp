#include <iostream>
#include <string>
using namespace std;

template <class T1, class T2>
class Person;
template <class T1, class T2>
void printPerson2(Person<T1, T2> p)
{
  cout << p.m_Name << endl;
  cout << p.m_Age << endl;
}

template <class T1, class T2>
class Person
{
  friend void pritnePerson1(Person<T1, T2> p)
  {
    cout << p.m_Name << endl;
    cout << p.m_Age << endl;
  }
  friend void printPerson2<>(Person<T1, T2> p);

public:
  Person(T1 name, T2 age)
  {
    this->m_Name = name;
    this->m_Age = age;
  }

private:
  T1 m_Name;
  T2 m_Age;
};

void test01()
{
  Person<string, int> p("Tom", 20);
  // printPerson1(p);
}

void test02()
{
  Person<string, int> p("Bob", 12);
  printPerson2(p);
}

int main()
{
  test02();
  return 0;
}