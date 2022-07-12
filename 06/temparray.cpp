#include <iostream>
#include "head/MyArray.hpp"
using namespace std;

void printIntArray(MyArray<int> &arr)
{
  for (int i = 0; i < arr.getSize(); i++)
  {
    cout << arr[i] << endl;
  }
}

void test01()
{
  MyArray<int> arr1(5);

  for (int i = 0; i < 5; i++)
  {
    arr1.Push_Back(i);
  }

  cout << "arr1: " << endl;
  printIntArray(arr1);

  cout << arr1.getCapacity() << endl;
  cout << arr1.getSize() << endl;

  MyArray<int> arr2(arr1);
  printIntArray(arr2);
  arr2.Pop_Back();
  cout << arr2.getCapacity() << endl;
  cout << arr2.getSize() << endl;

  // MyArray <int> arr2(arr1);

  // MyArray <int>arr3(100);
  // arr3 = arr1;
}

class Person
{
public:
  Person(){};
  Person(string name, int age)
  {
    this->m_Name = name;
    this->m_Age = age;
  }

  string m_Name;
  int m_Age;
};

void printPersonArray(MyArray<Person> &arr)
{
  for (int i = 0; i < arr.getSize(); i++)
  {
    cout << "Name: " << arr[i].m_Name << "Age: " << arr[i].m_Age << endl;
  }
}

void test02()
{
  MyArray<Person> arr(10);
  Person p1("孙悟空", 999);
  Person p2("打击", 20);
  Person p3("赵云", 999);
  Person p4("安琪拉", 999);
  Person p5("下里", 999);
  arr.Push_Back(p1);
  arr.Push_Back(p2);
  arr.Push_Back(p3);
  arr.Push_Back(p4);
  arr.Push_Back(p5);

  printPersonArray(arr);
  cout << "Capacity: " << arr.getCapacity() << endl;
  cout << "Size: " << arr.getSize() << endl;
}

int main()
{
  test02();
  return 0;
}