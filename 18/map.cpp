#include <map>
#include <iostream>
using namespace std;

void printMap(map<int, int> &m)
{
  for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
  {
    cout << "key: " << (*it).first << " "
         << "value: " << it->second << endl;
  }
}

void test01()
{
  map<int, int> m;
  m.insert(pair<int, int>(1, 10));
  m.insert(pair<int, int>(2, 20));
  m.insert(pair<int, int>(3, 30));
  m.insert(pair<int, int>(4, 40));
  printMap(m);

  map<int, int> m2(m);
  map<int, int> m3 = m2;
  printMap(m3);
  m3.insert(pair<int, int>(5, 50));
  m.swap(m3);
  printMap(m);
  printMap(m3);
}

void test02()
{
  map<int, int> m;
  m.insert(pair<int, int>(1, 10));
  m.insert(pair<int, int>(2, 20));
  m.insert(pair<int, int>(3, 30));
  m.insert(pair<int, int>(4, 40));

  map<int, int> m2(m);
  m2.erase(2);
  m2.erase(4);

  cout << m.size() << endl;
  cout << m.empty() << endl;
  m.swap(m2);
  cout << m.size() << endl;
  cout << m2.size() << endl;
}

void test03()
{
  map<int, int> m;
  m.insert(pair<int, int>(1, 10));
  m.insert(make_pair(2, 20));
  m.insert(map<int, int>::value_type(3, 30));
  m[4] = 40;
  printMap(m);
}

int main()
{
  test03();
  return 0;
}