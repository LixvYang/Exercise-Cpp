#include <iostream>
#include <memory>
#include <vector>
using namespace std;

shared_ptr<vector<int>> alloc_vector()
{
  return make_shared<vector<int>>();
}

void assign_vector(shared_ptr<vector<int>> p)
{
  int i;
  for (i = 0; i < 10; i++)
  {
    p->push_back(i);
  }
}

void print_vector(shared_ptr<vector<int>> p)
{
  for (auto i : *p)
  {
    cout << i << endl;
  }
}

int main()
{
  auto p =  alloc_vector();
  assign_vector(p);
  print_vector(p);
  return 0;
}
