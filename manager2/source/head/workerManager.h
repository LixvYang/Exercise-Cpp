#pragma once // 防止头文件重复包含
#include <iostream> 
#include <worker.h>

using namespace std;

class WorkderManager
{
public:
  WorkderManager();
  void Show_Menu();
  void exitSystem();
  void Add_Emp();
  ~WorkderManager();

  int m_EmpNum;

  Worker ** m_EmpArray;
};