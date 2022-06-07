#include<iostream>
using namespace std;

int main() {
  // extern const int bufSize = 10;
  // bufSize = 512;
  // std::cout << bufSize << std::endl;

  // const int ci = 42;
  // const int &ri = ci;
  // cout << ri << endl;
  // const int ci = 1024;
  // const int &r1 = ci;
  // cout << r1 << endl;
  // cout << &ci << endl;
  // r1 = 42;
  // int &r2 = ci;

  /**
   * @brief 常量的临时拷贝
   */
  // int i = 42;
  // const int &r1 = i;
  // const int &r2 = 42;
  // const int &r3 = r1*2;
  // int &r4 = i;
  // double dval = 3.14;
  // const int &ri = dval;
  // cout << ri << endl;

  // const 指针
  // int errNumb = 0;
  // int *const curErr = &errNumb;
  // const double pi = 3.1415926;
  // const double *const pip = &pi;

// const int i = -1, &r = 0;
  // int i, *const cp;
  // int *pl, *const p2;
  int i2 = 2;          // // 底层const i是一个常量
  const int *const p3 = &i2;  
  i2 = 3;
  cout << *p3 << endl;
}