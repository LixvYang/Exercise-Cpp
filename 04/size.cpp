#include<iostream>
#include<string>

int main() {
  // int i; double d;
  // d = i = 3.5; i = d = 3.5;
  // std::cout << i << std::endl;
  // std::cout << d << std::endl;

  // double dval; int ival; int *pi;
  // dval = ival = *pi = 0;
  // std::cout << dval << std::endl;

  // auto pbeg = v.begin();
  // while (pbeg != v.end() && *pbeg >= 0) 
  // {
  //   cout << *pbeg++ << endl;
  // }

  // string s1 = "a string", *p = &sl;
  // auto n = sl.size()
  // n = (*p).size();
  // n = p->size();

  Sales_item item1, item2;
  cin >> item1 >> item2;
  if (item1.isbn() == item2.isbn()) {
    cout << item + item2 << endl;
    return 0;
  } else {
    cerr << "Data must refer to same ISBN" << endl;
    return -1;
  }

  if (item1.isbn() != item2.isbn()) 
    throw runtime_error("Data must refer to same ISBN");
  cout << item1 + item2 << end;
}