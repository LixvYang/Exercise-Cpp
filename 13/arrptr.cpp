#include <iostream>
#include <cstring>
using namespace std;

int main()
{
  {
    // 2X3(arr1);
    unsigned char arr1[2][3] = {{1, 2, 3}, {4, 5, 6}};
    unsigned char arr2[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    cout << "arr1[2][3] sizeof(arr1) = " << sizeof(arr1) << endl;
    cout << "arr1[2][3] sizeof(arr2) = " << sizeof(arr2) << endl;

    int a[3][4];
    cout << sizeof(a) << endl;
  }
  cout << "a" << endl;
  cout << "b" << endl;
  // 栈空间
  int arr1[10];
  memset(arr1, 0, sizeof(arr1)); // 数字可以通过sizeof获取大小
  int arr2[10] = {1, 2, 3, 4, 5};
  int arr3[32] = {1, 2, 3};
  int arr4[1024] = {0};
  int arr5[] = {1, 2, 3, 4};
  char str1[] = "test01";
  cout << "sizeof(arr5) = " << sizeof(arr5) << endl;
  cout << "sizeof(str1) = " << sizeof(str1) << endl;
  for (auto s : str1)
  {
    cout << s << "-" << endl;
  }

  for (int *b = begin(arr5); b != end(arr5); b++)
  {
    cout << *b << endl;
  }

  for (int i = 0; i < 3; i++)
  {
    cout << arr5[i] << endl;
  }
  cout << "arr5 的sizeof = " << sizeof(arr5) << endl;

  // 堆空间
  // begin(arr1);
  // end(arr1);
  //  find(begin(arr5), end(arr5), 3)
  int *parr1 = new int[1024];
  int psize = 2048;
  auto parr2 = new unsigned char[psize];
  // int tmp[psize];
  memset(parr2, 0, sizeof(parr2));
  auto parr3 = new int[psize];
  memset(parr3, 0, psize * sizeof(int));

  int *parr4 = new int[]{1, 2, 3};
  int *parr5 = new int[]{1, 2, 3, 6};
  // cout << "parr5 的sizeof = " << sizeof(parr5) << endl; 堆里面不适合这样
  cout << "parr5[2]= " << parr5[2] << endl;
  cout << "*(parr5+3) = " << *(parr5 + 3) << endl;
  for (int i = 0; i < 3; i++)
  {
    cout << parr5[i] << endl;
  }
  delete[] parr5;
  parr5 = nullptr;

  return 0;
}
