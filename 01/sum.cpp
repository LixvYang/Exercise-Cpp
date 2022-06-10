#include<iostream>

int main() {
  int val1 = 0, val2 = 0;

  std::cout << "Enter two numbers: ";
  std::cin >> val1 >> val2;

  while(val1 <= val2) {
    std::cout << val1 << " " << std::endl;
    ++val1;
  }


  return 0;
}
