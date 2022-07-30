#include <iostream>
#include <vector>
#include <memory>
#include <string>
using namespace std;

int main()
{
  shared_ptr<string> s_p_1 = make_shared<string>();
  unique_ptr<string> u_p_1 = make_unique<string>("Hello World");

  if (s_p_1 && s_p_1->empty())
  {
    *s_p_1 = "hi";
  }
  cout << *s_p_1 << endl;
  cout << &s_p_1 << endl;
  auto p6 = make_shared<vector<string>>();

  double *pd = new double(33);
  delete pd;

  const int *pci = new const int(1024);
  delete pci;

  int *p = new int(42);
  auto q = p;
  cout << *q << endl;
  delete p;
  p = nullptr;

  vector<int>* v_i = new vector<int>();
  cout << "v_i : " << v_i << endl;

  return 0;
}
