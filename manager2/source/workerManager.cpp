#include "head/workerManager.h"
#include "head/employee.h"
#include "head/manager.h"
#include "head/boss.h"
#include <iostream>
#include <fstream>
using namespace std;

WorkderManager::WorkderManager()
{
  ifstream ifs;
  ifs.open(FILENAME, ios::in);

  // 文件不存在的情况
  if (!ifs.is_open())
  {
    cout << "文件不存在" << endl;
    this->m_EmpNum = 0;
    this->m_FileIsEmpty = true;
    this->m_EmpArray = NULL;
    ifs.close();
    return ;
  }

  char ch;
  ifs >> ch;
  if (ifs.eof())
  {
    cout << "文件为空！" << endl;
    this->m_EmpNum = 0;
    this->m_FileIsEmpty = true;
    this->m_EmpArray = NULL;
    ifs.close();
    return ;
  }

  int num = this->get_EmpNum();
  cout << "职工个数为: " << num << endl;
  this->m_EmpNum = num;
}

WorkderManager::~WorkderManager()
{
  if (this->m_EmpArray != NULL)
  {
    delete[] this->m_EmpArray;
    this->m_EmpArray = NULL;
  }
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

void WorkderManager:: Add_Emp()
{
  cout << "请输入增加职工数量" << endl;

  int addNum = 0;
  cin >> addNum;
  cout << "输入成功" << endl;
  if (addNum > 0) 
  { 
    cout << "NewSize创建中" << endl;
    int newSize = this->m_EmpNum + addNum; // 新空间人数
    cout << "NewSize创建成功" << endl;

    cout << "newSpace创建中" << endl;
    Worker ** newSpace = new Worker*[newSize];
    cout << "newSpace成功" << endl;
    if (this->m_EmpArray != NULL)
    {
      for (int i = 0; i < this->m_EmpNum; i++)
      {
        newSpace[i] = this->m_EmpArray[i];
      }
    }
    cout << "开辟新空间成功" << endl;

    // 批量添加数据
    for (int i = 0; i < addNum; i++)
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
    delete newSpace;
    cout << " 成功添加 " << addNum << "名新职工" << endl;
    this->save();
  } else {
    cout << "输入有误" << endl;
  }
  system("pause");
  system("cls");
}
 
void WorkderManager::save() 
{
  ofstream ofs;
  ofs.open(FILENAME, ios::out);

  for (int i = 0; i < this->m_EmpNum; i++)
  {
    ofs << this->m_EmpArray[i]->m_Id << " "
        << this->m_EmpArray[i]->m_Name << " "
        << this->m_EmpArray[i]->m_DeptId << endl;
  }
  ofs.close();
}

int WorkderManager::get_EmpNum()
{
  ifstream ifs;
  ifs.open(FILENAME, ios::in);

  int id;
  string name;
  int dId;

  int num;

  while (ifs >> id && ifs >> name && ifs >> dId)
  {
    num++;
  }
  
  ifs.close();
  return num;
}
