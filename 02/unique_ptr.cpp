#include <iostream>
#include <memory>
using namespace std;
struct A;
struct B;

struct A
{
  shared_ptr<B> pointer;
  ~A()
  {
    cout << "A 被销毁" << endl;
  }
};

struct B
{
  shared_ptr<A> pointer;
  ~B()
  {
    cout << "B 被销毁" << endl;
  }
};

int main()
{
  auto a = make_shared<A>();
  auto b = make_shared<B>();
  a->pointer = b;
  b->pointer = a;
  
  // cout << "b->pointer.lock().use_count() : " << b->pointer.lock().use_count() << endl;
  // cout << "b->pointer.expired() : " << b->pointer.expired() << endl;
  // cout << "b->pointer.lock().use_count() : " << b->pointer.lock().use_count() << endl;
  cout << "a.use_count() : " << a.use_count() << endl;
  cout << "b.use_count() : " <<  b.use_count() << endl;
  
  return 0;
}
