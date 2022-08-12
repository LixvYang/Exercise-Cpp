#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>

using namespace std;

int main()
{
  int ia[6] = {25, 232l, 232,3, 2 ,1};
  vector<int, allocator<int>> vi(ia, ia+6);
  cout << count_if(vi.begin(), vi.end(), not1(bind2nd(less<int>(), 40)));
  return 0;
}
