#include <iostream>
using namespace std;
#include <list>

void printList(const list<int> &L)
{
  for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
  {
    cout << *it << " ";
  }
  cout << endl;
}

void test01()
{
  list<int> L1;

  L1.push_back(10);
  L1.push_back(20);
  L1.push_back(30);
  L1.push_back(40);
  L1.push_back(50);
  printList(L1);
  cout << "L1: Size(): " <<  L1.size() << endl;
  L1.resize(0);
  cout << "L1: empty(): " <<  L1.empty() << endl;
  L1.resize(10, 10000);
  printList(L1);
  cout << "L1: Size(): " <<  L1.size() << endl;
  cout << "L1: Size(): " <<  L1.size() << endl;
  cout << "L1: Size(): " <<  L1.size() << endl;
}

int main()
{
  
  test01();
  return 0;
}
