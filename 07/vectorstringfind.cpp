#include<iostream>
#include<string>
#include<vector>
using namespace std;

void test01()
{
  string str1 = "qwedqwq";
  int pos = str1.find("q");
  cout << "Pos = " << pos << endl;
}

int main()
{
  test01();
  return 0;
}