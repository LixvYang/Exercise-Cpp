#include <list>
#include <iostream>
using namespace std;

void printList(list<int> &l1)
{
  for (list<int>::const_iterator it = l1.begin(); it != l1.end(); it++)
  {
    cout << *it << " ";
  }
  cout << endl;
}

// void test()
// {
//   list<int> l1;
//   l1.push_back(10);
//   l1.push_back(20);
//   l1.push_back(30);
//   l1.push_back(40);
//   list<int> l2(l1.begin(), l1.end());
//   list<int> l3(10, 10000);
//   printList(l1);
//   printList(l2);
//   printList(l3);
// }

// void test()
// {
//   list<int> l1;
//   l1.push_back(10);
//   l1.push_back(20);
//   l1.push_back(30);
//   l1.push_back(40);
//   l1.push_back(50);
//   printList(l1);

//   list<int> l2 = l1;
//   l2.push_back(60);
//   printList(l2);
//   list<int>l3;
//   l3.assign(l2.begin(), l2.end());
//   list<int> l4;
//   l4.assign(10, 1000);
//   l1.swap(l2);
//   printList(l1);
//   printList(l2);

// }

void test()
{
  
}

int main()
{
  test();
  return 0;
}