#include <iostream>
#include <string>
using namespace std;
#define MAX 2000

struct Person
{
  string m_Name;
  int m_Sex;
  int m_Age;
  string m_Phone;
  string m_Address;
};

struct Addressbooks
{
  struct Person personArray[MAX];
  int m_Size;
};

void addPerson(Addressbooks * abs) {
  if (abs->m_Size == MAX) {
    cout << "通讯录满了" << endl;
    return ;
  }
  else 
  {
    string name;
    cout << "请输入姓名: " << endl;
    cin >> name;
    abs->personArray[abs->m_Size].m_Name = name;

    cout << "请输入性别： " << endl;
    cout << "1 男 2 女" << endl;
    int sex = 0;

    while (true)
    {
      if (sex == 1 || sex == 2) {
        abs->personArray[abs->m_Size].m_Sex = sex;
        break;
      }
    }
     
  }
}
int slowIndex = 0;
for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
    if (val != nums[fastIndex]) {
        nums[slowIndex++] = nums[fastIndex];
    }
}
return slowIndex;





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
  Addressbooks abs;
  abs.m_Size = 0;

  
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
      addPerson(&abs);
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