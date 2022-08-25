#include <set>
#include <iostream>
using namespace std;

void printSet(set<int> &s1)
{
  for (set<int>::const_iterator it = s1.begin(); it != s1.end(); it++)
  {
    cout << *it << " ";
  }
  cout << endl;
}

void test01()
{
  set<int> s1;
  s1.insert(10);
  s1.insert(40);
  s1.insert(30);

  s1.insert(20);
  s1.insert(30);

  // 所有元素插入会自动排序
  // set元素不允许被插入重复的值
  printSet(s1);

  set<int> s2(s1);
  set<int> s3 = s2;
}

void test02()
{
  set<int> s1;
  s1.insert(10);
  s1.insert(30);
  s1.insert(20);
  s1.insert(40);
  if (s1.empty())
  {
    cout << "s1 empty " << endl;
  }
  else
  {
    cout << "s1 not empty " << endl;
    cout << "s1.size()" << endl;
    cout << s1.size() << endl;
  }
  set<int> s2;
  s2.insert(100);
  s2.insert(200);
  s2.insert(300);
  s2.insert(400);
  cout << "交换hou" << endl;
  s1.swap(s2);
  printSet(s1);
  printSet(s2);
}

void test03()
{
  set<int> s1;
  s1.insert(10);
  s1.insert(30);
  s1.insert(20);
  s1.insert(40);
  printSet(s1);
  // erase
  s1.erase(s1.begin());
  printSet(s1);
  s1.erase(30);
  printSet(s1);
  s1.erase(s1.begin(), s1.end());
  s1.clear();
  printSet(s1);
}

void test04()
{
  set<int> s1;
  s1.insert(10);
  s1.insert(20);
  s1.insert(30);
  s1.insert(40);
  set<int>::iterator pos = s1.find(10);
  if (pos != s1.end())
  {
    cout << "found  :" << *pos << endl;
  }
  else
  {
    cout << "not fount;" << endl;
  }
}

void test05()
{
  set<int> s1;
  s1.insert(10);
  s1.insert(20);
  s1.insert(30);
  s1.insert(30);
  s1.insert(30);
  s1.insert(40);

  // 对于set而言 统计的结果要么是0 要么是1；
  size_t num = s1.count(30);
  cout << num << endl;
}

class MyCompare
{
public:
  bool operator()(int v1, int v2)
  {
    return v1 > v2;
  }
};

void test06()
{
  set<int, MyCompare> s1;
  s1.insert(10);
  s1.insert(20);
  s1.insert(30);
  s1.insert(40);
  for (set<int, MyCompare>::iterator it = s1.begin(); it != s1.end(); it++)
  {
    cout << *it << " ";
  }
  cout << endl;
}

int main()
{
  test06();
  return 0;
}