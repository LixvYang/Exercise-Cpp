#include <iostream>
#include <string>
#include "Sales_data.h"

// struct Sales_data {
//   std::string bookNo;
//   unsigned units_sold = 0;
//   double revenue = 0.0;
// };

int main() {
  Sales_data data1, data2;
  // 读入data1, data2 的代码
  double price = 0;
  std::cin >> data1.bookNo >> data1.units_sold >> price;
  data1.revenue = data1.units_sold * price;

  std::cin >> data2.bookNo >> data2.units_sold >> price;
  data2.revenue = data2.units_sold * price;

  // 检查data1和data的ISBN是否有相同代码
  if (data1.bookNo == data2.bookNo) {
    unsigned totalCnt = data1.units_sold + data2.units_sold;
    double totalRevenue = data1.revenue + data2.revenue;
    std::cout << data1.bookNo << " " << totalCnt << " "
              << totalRevenue << " ";
    if (totalCnt != 0) {
      std::cout << totalRevenue/totalCnt << std::endl;
    } else {
      std::cout << "(No sales)" << std::endl;
      return 0;
    }
  } else {
    std::cerr << "Data must refer to the same IBSN" << std::endl;
    return -1;
  }

  // 如果相同data1和data2总和


}
