#include<iostream>

// int main() {
//   int sum = 0;

//   for(int val = 1; val <= 10; ++val) {
//     sum += val;
//     std::cout << valcl << " " << std::endl;
//   }
//   std::cout << "Sum of 1 to 10 inclusive is " << sum << std::endl;
//   return 0;
// }



// int main() {
//   int sum = 0;

//   for(int val = 10; val >= 0; --val) {
//     // sum += val;
//     std::cout << val << " " << std::endl;
//   }
//   // std::cout << "Sum of 1 to 10 inclusive is " << sum << std::endl;
//   return 0;
// }


int main() {
  int val1 = 0, val2 = 0;
  std::cin >> val1 >> val2;

  for(int val = val1; val <= val2; ++val) {
    std::cout << val << " " << std::endl;
  }
  // std::cout << "Sum of 1 to 10 inclusive is " << sum << std::endl;
  return 0;
}