#include <iostream>
#include <memory>
using namespace std;

int main()
{
  auto pointer = make_shared<int>(10);
  auto pointer2 = pointer;
  auto pointer3 = pointer;
  std::cout << "pointer.use_count() = " << pointer.use_count() << std::endl;   // 3
  std::cout << "pointer2.use_count() = " << pointer2.use_count() << std::endl; // 3
  std::cout << "pointer3.use_count() = " << pointer3.use_count() << std::endl; // 3

  pointer2.reset();
  std::cout << "reset pointer2:" << std::endl;
  std::cout << "pointer.use_count() = " << pointer.use_count() << std::endl; // 2
  std::cout << "pointer2.use_count() = "
            << pointer2.use_count() << std::endl;                              // pointer2 已 reset; 0
  std::cout << "pointer3.use_count() = " << pointer3.use_count() << std::endl; // 2
  pointer3.reset();
  std::cout << "reset pointer3:" << std::endl;
  std::cout << "pointer.use_count() = " << pointer.use_count() << std::endl;   // 1
  std::cout << "pointer2.use_count() = " << pointer2.use_count() << std::endl; // 0
  std::cout << "pointer3.use_count() = "
            << pointer3.use_count() << std::endl; // pointer3 已 reset; 0
  // cout << "pointer.use_count() : " << pointer.use_count() << endl;

  int *p = pointer.get(); 
  cout << *p << endl;
  cout << pointer.get() << endl;
  cout << p << endl; // p 和 pointer.get() 是一个地址
  cout << &p << endl;

  return 0;
}