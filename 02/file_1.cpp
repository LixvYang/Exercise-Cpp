#include<iostream>

int main() {
  // const int bufSize = 10;
  // bufSize = 512;
  // std::cout << bufferSize << std::endl;

  const int ci = 1024;
  const int &ri = ci;
  // ri = 42;
  // int &r2 = ci;
  std::cout << ri << std::endl;
  int &r2 = ci;

  
}