#include <iostream>
using namespace std;

template <class T>
void mySwap(T&a, T&b)
{
  T temp = a;
  a = b;
  b = temp;
}

template <typename T>
void mySort(T arr[], int len)
{
  for (int i = 0; i < len; i++)
  {
    int max = i;
    for (int j = i+1; j < len; j++)
    {
      if (arr[max] < arr[i]) 
      {
        max = j;
      }
    }
    if (max != i)
    {
      mySwap(arr[max], arr[i]);
    }
  }
}

template <typename T>
void printArray(T arr[], int len)
{
  for (int i = 0; i < len; i++)
  {
    cout << arr[i] << endl;
  }
}

void test01()
{
  char charArr[] = "asdasji";
  int num = sizeof(charArr) / sizeof(char);
  mySort(charArr, num);
  printArray(charArr, num);
}

void test02()
{
  int intArr[] = {1, 2, 2,3 ,45,6,8,4, 2,1, 2,};
  int num = sizeof(intArr)/sizeof(int);

  mySort(intArr, num);
  printArray(intArr, num);
}

int main()
{
  // test01();
  test02();
  return 0;
}