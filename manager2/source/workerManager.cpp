#include "head/workerManager.h"
#include "head/employee.h"
#include "head/manager.h"
#include "head/boss.h"

WorkderManager::WorkderManager()
{

}

WorkderManager::~WorkderManager()
{

}

void WorkderManager::Show_Menu()
{
  cout << "*****************************" << endl;
  cout << "****** 欢迎使用职工管理系统!*****" << endl;
  cout << "********0 退出管理系统*******" << endl;
  cout << "********1 增加职工信息*******" << endl;
  cout << "********2 显示职工信息*******" << endl;
  cout << "********3 删除离职员工*******" << endl;
  cout << "********4 修改职工信息*******" << endl;
  cout << "********5 查找职工信息*******" << endl;
  cout << "********6 按照编号排序*******" << endl;
  cout << "********7 清空所有文档*******" << endl;
  cout << "*****************************" << endl;
  cout << endl;
}

void WorkderManager::exitSystem()
{
  cout << "欢迎下次使用" << endl;
  system("pause");
  exit(0);
}

void WorkderManager::Add_Emp()
{
  cout << "请输入增加职工数量" << endl;

  int add_Num = 0;
  cin >> add_Num;
  if (add_Num > 0) 
  {
    int newSize = this->m_EmpNum + add_Num;

    Worker ** newSpace = new Worker * [newSize];
    if (this->m_EmpArray != NULL)
    {
      for (int i = 0; i < this->m_EmpNum; i++)
      {
        newSpace[i] = this->m_EmpArray[i];
      }
    }

    for (int i = 0; i < add_Num; i++)
    {
      int id;
      string name;
      int dSelect;

      cout << "请输入第 " << i+1 << " 个新职工编号： " << endl;
      cin >> id;

      cout << "请输入第 " << i+1 << " 个新姓名编号： " << endl;
      cin >> name;

      cout << "请选择该职工的岗位： " << endl;
      cout << "1. 普通职工 " << endl;
      cout << "2. 经理 " << endl;
      cout << "3. 老板 " << endl;
      cin >> dSelect;

      Worker * worker = NULL;
      switch (dSelect)
      {
      case 1:
        worker = new Employee(id, name, 1);
        break;
      case 2:
        worker = new Manager(id, name, 2);
        break;
      case 3:
        worker = new Boss(id, name, 2);
        break;
      default:
        break;
      }
      newSpace[this->m_EmpNum+i] = worker;
    }
    delete[] this->m_EmpArray;
    this->m_EmpArray = newSpace;
    this->m_EmpNum = newSize;
    cout << " 成功添加 " << add_Num << "名新职工" << endl;
  } else {
    cout << "输入有误" << endl;
  }
  system("pause");
  system("cls");
}
