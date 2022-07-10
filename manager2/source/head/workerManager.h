#pragma once // 防止头文件重复包含
#include <iostream> 
#include <fstream>
#include "worker.h"
#define FILENAME "empFile.txt"

using namespace std;

class WorkderManager
{
public:
  WorkderManager();
  void Show_Menu();
  void exitSystem();
  void Add_Emp();
  void save();
  ~WorkderManager();

  int m_EmpNum;

  Worker ** m_EmpArray;
};