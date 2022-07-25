#include <iostream>
#include <iterator>
using namespace std;
#include <algorithm>
#include <vector>

class GreaterFive
{
  public:
    bool operator()(int val)
    { 
      return val > 5;
    }
};

void test01()
{
  vector<int> v;
  for (int i = 0; i < 10; i++)
  {
    v.push_back(i);
  }

  vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());
  if (it == v.end())
  {
    cout << "没有找到" << endl;
  }
  else
  {
    cout << "找到大于5的数字为" << *it << endl;
  }

}


int main()
{
  test01();
  return 0;
}
