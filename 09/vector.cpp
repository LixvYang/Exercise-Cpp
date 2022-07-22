#include <iostream>
#include <list>
#include <deque>
#include <vector>
#include <algorithm>
#include <array>
using namespace std;
bool testFind(vector<int>::const_iterator vBegin, vector<int>::const_iterator vEnd, int val);

void myPrint(int val)
{
  cout << val << endl;
}

void test01()
{

  vector<int> v;
  for (int i = 0; i < 10; i++)
  {
    v.push_back(i);
  }
  vector<int>::const_iterator vBegin = v.begin();
  vector<int>::const_iterator vEnd = v.end();
  while (vBegin != vEnd) 
  {
    cout << *vBegin << endl;
    vBegin++;
  }
  // for_each(v.begin(), v.end(), myPrint);
  for (vector<int>::reverse_iterator vRBegin = v.rbegin(); vRBegin != v.rend(); vRBegin++)
  {
    cout << *vRBegin << endl;
  }
}

void test02()
{
  vector<int> v;
  for (int i = 0; i < 10; i++)
  {
    v.push_back(i);
  }
  bool ifFind = testFind(v.begin(), v.end(), 1);
  cout << ifFind << endl;
}

bool testFind(vector<int>::const_iterator vBegin, vector<int>::const_iterator vEnd, int val)
{
  while (vBegin != vEnd) {
    if (*vBegin == val) 
    {
      return true;
    } 
    vBegin++;
  }
  return false;
  
}

void test3()
{
  vector<int> vec;
  // vector<int> vec(10);
  // vector<int> vec(10, 1);
  // vector<int> vec{ 1, 2, 3, 4, 5 };
  // vector<int> vec(vec1);
  // vector<int> vec(vec1.begin(), vec1.end());
}

void test04()
{
  array<int, 42> arr;
  cout << arr.size() << endl;
}

void test05()
{
  list<const char *> l {"niha", "Hello World" };
  vector<string> vec;
  vec.assign(l.rbegin(), l.rend());
  for (auto ptr : vec)
  {
    cout << ptr << endl;
  }
}

void test06()
{
  deque<string> dep;
  for (string str; cin >> str; dep.push_back(str));
  for(auto iter = dep.cbegin(); iter != dep.cend(); ++iter)
  {
    cout << *iter << endl;
  }
}

void test07()
{
  vector<int> vec;
  vec.push_back(12);
  vec.push_back(11);
  vec.push_back(42);
  int val = 42;
  auto result = find(vec.cbegin(), vec.cend(), val);
  cout << "The value " << val << (result == vec.cend() ? "is not present" : " is present") << endl;
}


int main()
{
  test07();
  return 0;
}

