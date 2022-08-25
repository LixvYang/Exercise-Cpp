#include <iostream>
#include <utility>
using namespace std;

void test01()
{
  pair<string, int> p("Tom", 20);
  cout << "name: " << p.first << endl;
  cout << "age: " << p.second << endl;

  pair<string, int> p2 = make_pair("jery", 30);
  cout << "name: " << p2.first << endl;
  cout << "age: " << p2.second << endl;
}

int main()
{
  test01();
  return 0;
}