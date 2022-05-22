#include<iostream>

int reused = 42;
int main() {
  // int sum = 0, value, units_sold = 0;

  // Sales_item item;
  // std::string book("0-201-78345-X");

  // int units_sold = 0;
  // int units_sold = {0}; 
  // int units_sold{0};
  // int units_sold(0);
  // double wage;
  // double salary = wage = 9999.99;
  // std::cin >> input_value;

    // int local_int;
    // std::string local_str;

    // std::cout << global_str << std::endl;
    // std::cout << global_int << std::endl;
    // std::cout << local_str << std::endl;
    // std::cout << local_int << std::endl;
  // extern int i;
  // int j;
  // std::cout << i << std::endl;
  // std::cout << j << std::endl;
  // int _or_2 = 1;
  // std::cout << _or_2 << std::endl;

  int unique = 0;
  std::cout << reused << " " << unique << std::endl;
  int reused = 0;
  std::cout << reused << " " << unique << std::endl;
  std::cout << ::reused << " " << unique << std::endl;

  return 0;
}