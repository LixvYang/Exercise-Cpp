#include <iostream>
#include <deque>
#include <iterator>
using namespace std;

void printDeque(const deque<int>& d)
{
  for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;
}

void test01()
{
  deque<int> d1;
  for (int i = 0; i < 10; i++) {
    d1.push_back(i);
  }

  printDeque(d1);
  d1.push_back(100);
  d1.push_back(200);
  printDeque(d1);

  d1.pop_front();
  printDeque(d1);
  d1.pop_back();
  printDeque(d1);

  d1.insert(d1.begin(), 1000);
  printDeque(d1);
}

int main()
{
  test01();

  return 0;
}


