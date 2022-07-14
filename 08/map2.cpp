#include <iostream>
#include <map>
using namespace std;

void printMap(map<int, int> &m)
{
  for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
  {
    cout << "Key = " << (*it).first << " Value: " << it->second << endl;
  }
  cout << endl; 
}

void test01()
{
  map<int, int> m;
  m.insert(pair<int, int>(1, 10));
  m.insert(pair<int, int>(3, 30));
  m.insert(pair<int, int>(4, 40));
  m.insert(pair<int, int>(2, 20));
  printMap(m);
  if(m.empty()) {
    cout << "m 为空" << endl; 
  }
  else {
    cout << "m 不为空 " << endl;
    cout << "m 的大小为" << m.size() << endl;
  }
}
void test02()
{
  map<int, int> m;
  m.insert(pair<int, int>(1, 10));
  m.insert(pair<int, int>(3, 30));
  m.insert(pair<int, int>(4, 40));
  m.insert(pair<int, int>(2, 20));

  map<int, int> m2;
  m2.insert(pair<int, int>(4, 10));
  m2.insert(pair<int, int>(5, 30));
  m2.insert(pair<int, int>(6, 40));
  m2.insert(pair<int, int>(7, 20));

  cout << "Swap pre" << endl;
  printMap(m);
  printMap(m2);

  m.swap(m2);
  printMap(m);
  printMap(m2);
}

int main()
{
  test02();
  return 0;
}
  
