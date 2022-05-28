#include<iostream>

int main() {
  // extern const int bufSize = 10;
  // bufSize = 512;
  // std::cout << bufSize << std::endl;

  const int ci = 42;
  const int &ri = ci;

  int &r2 = ci;

}