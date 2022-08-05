#include <iostream>
#include <memory>
using namespace std;

int main()
{
  shared_ptr<int> pointer = make_shared<int>(10);
  shared_ptr<int> pointer2 = pointer;
  auto pointer3 = pointer;
  int *p = pointer.get();
  cout << *p << endl;
  std::cout << "pointer.use_count() = " << pointer.use_count() << std::endl;   // 3
  std::cout << "pointer2.use_count() = " << pointer2.use_count() << std::endl; // 3
  std::cout << "pointer3.use_count() = " << pointer3.use_count() << std::endl; // 3

  pointer2.reset();
  std::cout << "reset pointer2:" << std::endl;
  std::cout << "pointer.use_count() = " << pointer.use_count() << std::endl;   // 2
  std::cout << "pointer2.use_count() = " << pointer2.use_count() << std::endl;           // pointer2 已 reset; 0

  return 0;
}
