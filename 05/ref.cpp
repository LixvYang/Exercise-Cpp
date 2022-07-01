#include<iostream>
// void mySwap(int * a, int * b);

// void mySwap(int * a, int * b)
// {
//   int tmp = *a;
//   *a = *b;
//   *b = tmp;
// }

void mySwap03(int & a, int & b) 
{
  int tmp = a;
  a = b;
  b = tmp;
}

int main() {
  using namespace std;
  int a = 10;
  int b = 20;

  mySwap03(a, b);
  cout << "a: " << a << endl;
  cout << "b: " << b << endl;


  return 0;
}
