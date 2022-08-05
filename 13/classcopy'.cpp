#include <iostream>

class Foo
{
  Foo() = default;
  Foo(const Foo&);
  ~Foo();
};

int main()
{

  return 0;
}
