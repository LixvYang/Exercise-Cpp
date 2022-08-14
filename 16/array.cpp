#include <array>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <list>
using namespace std;
const int ASIZE = 500000;

namespace jj01
{
  void test_array()
  {
    cout << "\ntest Array()..........\n";
    list<int> c;

    array<long, ASIZE> c;
    clock_t timeStart = clock();
    for (long i = 0; i < ASIZE; ++i) {
      c[i] = rand();
    }
    cout << (clock()-timeStart) << endl;
    cout << c.size() << endl;
    cout << c.front() << endl;
    cout << c.back() << endl;
    cout << c.data() << endl;

  }

} // namespace jj01
