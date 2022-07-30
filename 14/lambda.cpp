#include <iostream>
using namespace std;

int main()
{
  int x = 10;
  int y = 20;
  auto print = [](int s) { cout << "value: " << s << endl; };
  auto lambAdd = [x](int a) {
    return a + x;
  };

  auto lambAdd2 = [&x](int a, int b) {
    x = x+5;
    return a + b + x;
  };
  auto iSum = lambAdd(10);
  auto iSum2 = lambAdd2(10, 11);
  print(iSum);
  print(iSum2);
  print(x);
  return 0;
}
