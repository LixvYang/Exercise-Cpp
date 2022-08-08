#include <iostream>
#include <string>
using namespace std;

class Person
{
  public:
    Person()=default;
    explicit Person(string name, int age) : m_Name(name), m_Age(age) {}
    bool operator==(Person &p);
  private:
    string m_Name;
    int m_Age;
};

bool Person::operator==(Person &p)
{
  if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
  {
    return true;
  } else 
  {
    return false;
  }
} 

void test01()
{
  Person p1("Tom", 18);
  Person p2("Tom", 18);

  if (p1 == p2)
  {
    cout << "p1 == p2" << endl;
  } else {
    cout << "p1 != p2" << endl;
  }
}

int main()
{
  test01();
  return 0;
}
