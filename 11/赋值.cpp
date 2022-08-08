#include <iostream>
using namespace std;

class Person
{
  public:
    Person& operator=(Person &p);
    Person(int name) : m_Name(new int(name)) {}
    ~Person()
    {
      if (m_Name != nullptr)
      {
        delete m_Name;
        m_Name = nullptr;
      }
    }
    int PersonName() {return *this->m_Name;}
    int *m_Name;


};

Person& Person::operator=(Person &p)
{
  if (this->m_Name != nullptr) 
  {
    delete this->m_Name;
    this->m_Name = nullptr;
  };
  this->m_Name = new int (*p.m_Name);
  return *this;
}

void test01()
{
  Person p1(18);
  Person p2(20);
  Person p3(30);
  p3 = p2 = p1;
  cout << "p1 的name: " << *p1.m_Name << endl;
  cout << "p2 的name: " << *p2.m_Name << endl;
  cout << "p3 的name: " << *p3.m_Name << endl;
}

int main()
{
  test01();
  return 0;
}
