#include <vector>
#include <iostream>
using namespace std;

void printVector(vector<int> &v)
{
  for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
  {
    cout << *it << " ";
  }
  cout << endl;
}

// void test01()
// {
//   vector<int> v1;

//   for (int i = 0; i < 10; i++)
//   {
//     v1.push_back(i);
//   }
//   vector<int>v2(v1);
//   printVector(v1);
//   // n 个 value
//   vector<int>v3(10, 1000);
//   printVector(v3);

//   //
//   vector<int>v4(v1.begin(), v1.end());
//   printVector(v4);
// }

// void test02()
// {
//   vector<int> v1;
//   v1.push_back(10);
//   v1.push_back(20);
//   v1.push_back(20);
//   v1.push_back(30);
//   v1.push_back(40);
//   v1.push_back(50);

//   printVector(v1);
//   v1.pop_back();
//   printVector(v1);
//   v1.insert(v1.begin()++, 2, 1000);
//   printVector(v1);
//   v1.erase(v1.begin());
//   printVector(v1);
//   v1.erase(v1.begin(), v1.end());
//   printVector(v1);
// }

void test03()
{
  vector<int> v;
  int *p = nullptr;
  int num = 0;
  v.reserve(100000);
  for (int i = 0; i < 100000; i++)
  {
    v.push_back(i);
    if (p != &v[0])
    {
      p = &v[0];
      num++;
    }
  }
  cout << "num = " << num << endl;
}

int main()
{
  test03();
  return 0;
}