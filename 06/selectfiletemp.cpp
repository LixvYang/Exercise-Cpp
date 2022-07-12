#include <iostream>
#include <string>
#include "head/person.hpp"
using namespace std;

void test01()
{
  Person<string, int> p("Tom", 20);
  p.showPerson();
}

int main()
{
  test01();
  return 0;
}
