#include <iostream>
#include <memory>
using namespace std;

int main(int argc, char const *argv[])
{
  unique_ptr<int> u_i_p4 = make_unique<int>(200);
  *u_i_p4 = 100;
  cout << *u_i_p4 << endl;
  cout << u_i_p4.get() << endl;
  return 0;
}
