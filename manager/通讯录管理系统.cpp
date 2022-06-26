#include <iostream>
using namespace std;

void showMenu() 
{
  cout << "1. 添加联系人" << endl;
  cout << "2. 显示联系人" << endl;
  cout << "3. 删除联系人" << endl;
  cout << "4. 查找联系人" << endl;
  cout << "5. 修改联系人" << endl;
  cout << "6. 清空联系人" << endl;
  cout << "0. 退出通讯录" << endl;
}

int main()
{
  int select = 0;
  
  while (true)
  {
    showMenu();

    cin >> select;
    switch (select)
    //  1. 添加联系人
    //  2. 显示联系人
    //  3. 删除联系人
    //  4. 查找联系人
    //  5. 修改联系人
    //  6. 清空联系人
    //  0. 退出通讯录
    {
    case 1: 
      break;
    case 2:
      break;
    case 3:
      break;
    case 4:
      break;
    case 5:
      break;
    case 6:
      break;
    case 0:
      cout << "欢迎下次使用" << endl;
      system("pause");
      return 0;
      break;
    } 
  }

  system("pause");
  return 0;
}