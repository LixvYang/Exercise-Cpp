#ifndef SALES_DATA_A
#define SALES_DATA_A
#include <string>
struct Sales_data
{
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};
#endif
