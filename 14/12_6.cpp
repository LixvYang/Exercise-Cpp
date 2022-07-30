#include <vector>
#include <iostream>
using namespace std;

vector<int>* alloc_vector()
{
  return new vector<int>();
}

void assign_vector(vector<int>* p) {
  int i ;
  while (cin >> i) {
    p->push_back(i);
  }
}

void print_vector(vector<int>& p)
{
  for (auto i : p)
  {
    cout << i << endl; 
  }
}


int main()
{
  auto p = alloc_vector();
  assign_vector(p);
  print_vector(*p);
  delete p;
  return 0;
}
