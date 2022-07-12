#include <iostream>
#include <string>
using namespace std;

template<class T1, class T2>
class Person
{
public:
  Person(T1 name, T2 age)
  {
    this->m_Name = name;
    this->m_Age = age;
  }

  void showPerson()
  {
    cout << "Name: " << this->m_Name << endl;
    cout << "Age: " << this->m_Age << endl;
  };

  T1 m_Name;
  T2 m_Age;
};

void printPerson1(Person<string, int>&p)
{
  p.showPerson();
}

void test01()
{
  Person<string, int>p("Lixin", 100);
  printPerson1(p);
}

template<typename T1, typename T2>
void printPerson2(Person<T1, T2>&p)
{ 
  p.showPerson();
}

void test02()
{
  Person<string, int>p("Wuyu", 100);
  printPerson2<string, int>(p);
}

template<class T>
void printPerson3( T &p)
{
  p.showPerson();
}

void test03()
{
  Person<string, int>p("tang", 200);
  printPerson3(p);
}


int main()
{
  test03();
  return 0;
}

