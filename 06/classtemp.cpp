#include <iostream>
#include <string>
using namespace std;

template<class NameType, class AgeType>
class Person
{
public:
  Person(NameType name, AgeType age = int)
  {
    this->m_Name = name;
    this->m_Age = age;
  }
  void showPerson()
  {
    cout << "Name: " << this->m_Name << endl;
    cout << "Age: " << this->m_Age << endl;
  };

  NameType m_Name;
  AgeType m_Age;

};

void test01()
{
  Person<string, int> p1("Lixin", 999);
  p1.showPerson();
}

int main()
{
  test01(); 
  return 0;

}

