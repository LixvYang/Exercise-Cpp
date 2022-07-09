#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void test01()
{  
  ifstream ifs;
  ifs.open("test.txt", ios::in);

  if (!ifs.is_open())
  {
    cout << "文件打开失败" << endl;
    return;
  }
  
  // char buf[1024] = {0};
  // while (ifs >> buf)
  // {
  //   cout << buf << endl;
  // }

  // char buf[1024] = {0};
  // while (ifs.getline(buf, sizeof(buf)))
  // {
  //   cout << buf << endl;
  // }
  string buf;
  while (getline(ifs, buf))
  {
    cout << buf << endl;
  }
  
  
  ifs.close();

};

int main()
{
  test01();
  return 0;
};