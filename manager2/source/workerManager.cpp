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

  this->m_EmpArray  = new Worker * [this->m_EmpNum];
  this->init_Emp();

  for (int i = 0; i < m_EmpNum; i++)
  {
    cout << "职工号:  " << this->m_EmpArray[i]->m_Id
         << "职工姓名:  " << this->m_EmpArray[i]->m_Name
         << "部门编号: " << this->m_EmpArray[i]->m_DeptId << endl;
  }
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

void WorkderManager::init_Emp()
{
  ifstream ifs;
  ifs.open(FILENAME, ios::in);

  int id;
  string name;
  int dId;

  int index = 0;
  while (ifs >> id && ifs >> name && ifs >> dId)
  { 
    Worker * worker = NULL;
    if (dId == 1)
    {
      worker = new Employee(id, name, dId);
    }
    else if (dId == 2)
    {
      worker = new Manager(id, name, dId);
    }
    else 
    {
      worker = new Boss(id, name, dId);
    }
    this->m_EmpArray[index] = worker;
    index++;
  }
}

void WorkderManager::Show_Emp()
{
  if (this->m_FileIsEmpty)
  {
    cout << "File NotFound" << endl;
  }
  else
  {
    for (int i = 0; i < m_EmpNum; i++)
    {
      this->m_EmpArray[i]->showInfo();
    }
  }
  system("pause");
  system("cls");
}

int WorkderManager::IsExist(int id)
{
  int index = -1;
  
  for (int i = 0; i < this->m_EmpNum; i++)
  {
    if (this->m_EmpArray[i]->m_Id == id)
    {
      index = i;
      break;
    }
  }
  return index;
}

void WorkderManager::Del_Emp()
{
  if (this->m_FileIsEmpty)
  {
    cout << "File Not Found" << endl;
  }
  else
  {
    cout << "Input you want delete dId: " << endl;
    int id = 0;
    cin >> id;

    int index = this->IsExist(id);
    if (index != -1)
    {
      for (int i = index; i < this->m_EmpNum-1; i++)
      {
        this->m_EmpArray[i] = this->m_EmpArray[i+1];
      }
      this->m_EmpNum--;
      this->save();
      cout << "Del Success! " << endl;
    }
    else
    {
      cout << "Delete fault, not fount" << endl;
    }
  }

  system("pause");
  system("cls");
}

void WorkderManager::Mod_Emp()
{
  if (this->m_FileIsEmpty)
  {
    cout <<   "File not found!" << endl;
  } 
  else
  {
    cout << "Please input mod id " << endl;
    int id;
    cin >> id;

    int ret =this->IsExist(id);
    if (ret != -1)
    {
      delete this->m_EmpArray[ret];
      int newId = 0;
      string newName = "";
      int dSelect = 0;

      cout << "查到: " << id << "号职工, please input new id: " << endl;
      cin >> newId;

      cout << " Please input new name" << endl;
      cin >> newName;

      cout << "Please input 岗位: " << endl;
      cout << "1. 普通职工" << endl;
      cout << "2. 经理" << endl;
      cout << "3. 老板 " << endl;
      cin >>  dSelect;

      Worker * worker = NULL;
      switch (dSelect)
      {
      case 1:
        worker = new Employee(newId, newName, dSelect);
        break;
      case 2:
        worker = new Manager(newId, newName, dSelect);
        break;
      case 3:
        worker = new Boss(newId, newName, dSelect);
        break;
      default:
        break;
      }
      this->m_EmpArray[ret] = worker;
      cout << "修改成功! " << this->m_EmpArray[ret]->m_DeptId << endl;
      this->save();
    } 
    else 
    {
      cout << "not found" << endl;
    }
  }
  system("pause");
  system("cls");
}

void WorkderManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		cout << "请输入查找的方式：" << endl;
		cout << "1、按职工编号查找" << endl;
		cout << "2、按姓名查找" << endl;

		int select = 0;
		cin >> select;


		if (select == 1) //按职工号查找
		{
			int id;
			cout << "请输入查找的职工编号：" << endl;
			cin >> id;

			int ret = IsExist(id);
			if (ret != -1)
			{
				cout << "查找成功！该职工信息如下：" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "查找失败，查无此人" << endl;
			}
		}
		else if(select == 2) //按姓名查找
		{
			string name;
			cout << "请输入查找的姓名：" << endl;
			cin >> name;

			bool flag = false;  //查找到的标志
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (m_EmpArray[i]->m_Name == name)
				{
					cout << "查找成功,职工编号为："
                           << m_EmpArray[i]->m_Id
                           << " 号的信息如下：" << endl;
					
					flag = true;

					this->m_EmpArray[i]->showInfo();
				}
			}
			if (flag == false)
			{
				//查无此人
				cout << "查找失败，查无此人" << endl;
			}
		}
		else
		{
			cout << "输入选项有误" << endl;
		}
	}


	system("pause");
	system("cls");
}

void WorkderManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序方式： " << endl;
		cout << "1、按职工号进行升序" << endl;
		cout << "2、按职工号进行降序" << endl;

		int select = 0;
		cin >> select;


		for (int i = 0; i < m_EmpNum; i++)
		{
			int minOrMax = i;
			for (int j = i + 1; j < m_EmpNum; j++)
			{
				if (select == 1) //升序
				{
					if (m_EmpArray[minOrMax]->m_Id > m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
				else  //降序
				{
					if (m_EmpArray[minOrMax]->m_Id < m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
			}

			if (i != minOrMax)
			{
				Worker * temp = m_EmpArray[i];
				m_EmpArray[i] = m_EmpArray[minOrMax];
				m_EmpArray[minOrMax] = temp;
			}

		}

		cout << "排序成功,排序后结果为：" << endl;
		this->save();
		this->Show_Emp();
	}

}

void WorkderManager::Clean_File()
{
	cout << "确认清空？" << endl;
	cout << "1、确认" << endl;
	cout << "2、返回" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//打开模式 ios::trunc 如果存在删除文件并重新创建
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
            for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i] != NULL)
				{
					delete this->m_EmpArray[i];
				}
			}
			this->m_EmpNum = 0;
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_FileIsEmpty = true;
		}
		cout << "清空成功！" << endl;
	}

	system("pause");
	system("cls");
}