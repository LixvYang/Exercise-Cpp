#include<iostream>

int main() {
  // int iVal = 24;
  // int &refVal = iVal;
  // refVal = 23;
  // int ii = refVal;
  // ii = 22;
  // std::cout << iVal << " " << refVal << std::endl;
  // std::cout << ii << std::endl;

  // int &rval3;
  // std::cout << rval3 << std::endl;
  // int i, &ri = i;
  // i = 5, ri = 10;
  // std::cout << i << " " << ri << std::endl;

  // int iVal = 42;
  // int &i = iVal;
  // int *p = &i;
  // std::cout << &iVal << std::endl;

  // int i = 42;
  // int *p = &i;
  // // p = &i;
  // // ir 是值  &ir是指向的地址
  // // p 是 指向的地址 *p是值
  // int &ir = i;
  // std::cout << &ir << std::endl;
  // std::cout << ir << std::endl;
  // std::cout << p << std::endl;
  // std::cout << *p << std::endl;

  // double obj = 3.14, &pd = &obj;
  // void *pv = &obj;
  // pv = pd;
  // int i = 42;
  // int p = 40;
  // int *pl= &i;
  // *pl = *pl * *pl;
  // pl = &p;
  // pl = &p;
  // std::cout << *pl << std::endl;
  // std::cout << i << std::endl;

  int age = 17;
  int &ageRef1 = age;
  // int *p = &age;
  // std::cout << *p << std::endl;
  std::cout << &ageRef1 << std::endl;
  std::cout << &age << std::endl;
  // std::cout << p << std::endl;

  
  // std::cout << &p << std::endl;
}