#ifndef __TEST__
#define __TEST__
#include <iostream>
using namespace std;

class A;
class B;
class C;

class C
{
  public:
    C() { cout << "C 创建" << endl; }
};

class B {
  public:
    B() { cout << "B 创建" << endl; };
};

class A : public B
{
  public:
    A() { 
      this->c = new C();
      cout << "A 创建" << endl; 
    };
    ~A() {
      delete c;
    }
  private:
    C *c;
};


#endif 
