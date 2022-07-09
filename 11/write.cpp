#include <iostream>
#include <fstream>
using namespace std;

void test01()
{
  // 1. 包含头文件stream

  // 2. 创建流对象
  ofstream ofs;

  ofs.open("test.txt", ios::out);

  ofs << "姓名: 张三" << endl;
  ofs << "姓名: 张三" << endl;
  ofs << "姓名: 张三" << endl;

  ofs.close();
};

int main()
{
  test01();
  return 0;
}