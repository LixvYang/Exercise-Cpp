#include <iostream>
#include <cstring>
using namespace std;

int main()
{
  // 栈空间
  int arr1[10];
  memset(arr1, 0, sizeof(arr1)); // 数字可以通过sizeof获取大小
  int arr2[10] = {1, 2, 3, 4, 5};
  int arr3[32] = {1,
                  2,
                  3};
  int arr4[1024] = {0};
  int arr5[] = {1, 2, 3, 4};
  char str1[] = "test01";
  cout << "sizeof(arr5) = " << sizeof(arr5) << endl;
  cout << "sizeof(str1) = " << sizeof(str1) << endl;

  // 堆空间
  int *parr1 = new int[1024];
  int psize = 2048;
  auto parr2 = new unsigned char[psize];
  // int tmp[psize];
  memset(parr2, 0, sizeof(parr2));
  auto parr3 = new int[psize];
  memset(parr3, 0, psize * sizeof(int));

  

  return 0;
}