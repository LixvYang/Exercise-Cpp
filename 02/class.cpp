#include<iostream>

// struct Sales_data { /** */ } accum, trans, *salesptr;
// //
// struct Sales_data {};
// Sales_data accum, trans, *salesptr;

// struct Foo {}
// struct Sales_data
// {
//   std::string bookNo;
//   std::string bookName;
//   unsigned units_sold = 0;
//   double revenue = 0.0;
//   double price = 0.0;
// }

class Sales_data 
{
public:
  Sales_data()=default;
  Sales_data(const Sales_data&);
  Sales_data& operator=(const Sales_data&);
private:
    
  
};

int main() {
  return 0;
}
