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
  int get_EmpNum();
  ~WorkderManager();

  int m_EmpNum;
  bool m_FileIsEmpty;
  Worker ** m_EmpArray;
};