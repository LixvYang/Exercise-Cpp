#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

void printVector(vector<int> &v)
{
  for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
  {
    cout << *it << " ";
  }
  cout << endl;
}

void test01()
{
  vector<int> v;
  for (int i = 0; i < 10; i++)
  {
    v.push_back(i);
  }
  cout << v.front() << endl;
  cout << v.back() << endl;
  printVector(v);


}

int main()
{
  test01();
  return 0;
}
