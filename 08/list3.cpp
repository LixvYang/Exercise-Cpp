#include <iostream>
using namespace std;
#include <list>

void printList(const list<int>&L)
{
  for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
  {
    cout << *it << " ";
  }
  cout << endl;
}

void test01()
{
  list<int> L;
  L.push_back(10);
  L.push_back(20);
  L.push_back(30);
  L.push_back(40);

  L.push_front(100);
  L.push_front(200);
  L.push_front(300);

  printList(L);
}

int main()
{
  
  test01();
  return 0;
}

