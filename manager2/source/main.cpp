#include <iostream>
#include "head/workerManager.h"
#include "head/worker.h"
#include "head/employee.h"
#include "head/boss.h"
#include "head/manager.h"

using namespace std;
void test()
{
  Worker * worker = NULL;
  worker = new Employee(1, "张三", 1);
  worker->showInfo();
  delete worker;
  
  worker = new Manager(1, "李四", 1);
  worker->showInfo();
  delete worker;

  worker = new Boss(1, "王五", 1);
  worker->showInfo();
  delete worker;

}


int main()
{
  test();

  WorkderManager wm;
  int choice = 0;
  while (true)
  {
    wm.Show_Menu();
    cout << "请输入你的选择:" << endl;
    cin >> choice ;
    switch (choice)
    {
    case 0:
      wm.exitSystem();
      break;
    case 1:
      wm.Add_Emp();
      break;
    case 2:
      wm.Show_Emp();
      break;
    case 3:
      wm.Del_Emp();
      break;
    case 4:
      wm.Mod_Emp();
      break;
    case 5:
      wm.Find_Emp();
      break;
    case 6:
      wm.Sort_Emp();
      break;
    case 7:
      wm.Clean_File();
      break;
    default:
      system("cls"); 
      break;
    }
  }
}
