#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Person
{
public:
  Person(string name, int age)
  {
    this->m_Name = name;
    this->m_Age = age;
  }

  string m_Name;
  int m_Age;
};

void test01()
{
  vector<Person> v;
  Person p1("aaa", 10);
  Person p2("bbb", 20);
  Person p3("ccc", 20);
  v.push_back(p1);
  v.push_back(p2);
  v.push_back(p3);

  for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
  {
    cout << "姓名:" << (*it).m_Name << "Age: " << (*it).m_Age << endl;
  }
}

//
void test02()
{
  vector<Person *> v;
  Person p1("aaa", 10);
  Person p2("bbb", 20);
  Person p3("ccc", 20);
  v.push_back(&p1);
  v.push_back(&p2);
  v.push_back(&p3);

  for (vector<Person *>::iterator it = v.begin(); it != v.end(); it++)
  {
    cout << "姓名:" << (*it)->m_Name << "Age: " << (*it)->m_Age << endl;
  }
}

int main()
{
  test02();
  return 0;
}