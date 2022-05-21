#include<iostream>
#include "include/Sales_item.h"

// int main() {
//   Sales_item book;

//   std::cin >> book;
//   std::cout << book << std::endl;

//   return 0;
// }

// int main() {
//   Sales_item item1, item2;
//   std::cin >> item1 >> item2;
//   std::cout << item1 + item2 << std::endl;
//   return 0;
// }

// int main() {
//   for (Sales_item item; std::cin >> item; std::cout << item << std::endl);
//   return 0;
// }

// int main() {
//   Sales_item item1, item2;
//   std::cin >> item1 >> item2;
//   if (item1.isbn() == item2.isbn()) {
//     std::cout << item1 + item2 << std::endl;
//     return 0;
//   } else {
//     std::cerr << "Data must refer to same ISBN" << std::endl;
//     return -1;
//   }
// }

// int main() {
//   Sales_item total;

//   if (std::cin >> total) {
//     Sales_item item;
//     if (total.isbn() == item.isbn()) {
//       total += item;
//     } else {
//       std::cout << total << std::endl;
//       total = item;
//     }
//     std::cout << total << std::endl;
//   } else {
//     std::cout << "No Data?" << std::endl;
//     return -1;
//   }
//   return 0;
// }

int main() {
  Sales_item currItem, valItem;
  if (std::cin >> currItem) {
    int cnt = 1;
    while (std::cin >> valItem) {
      if (valItem.isbn() == currItem.isbn()) {
        ++cnt;
      } else {
        std::cout << currItem << " occurs " << cnt << " times " << std::endl;
        currItem = valItem;
        cnt = 1; 
      }
    }
    std::cout << currItem << " occurs "<< cnt << " times " << std::endl;
  }
  return 0;
}