#pragma once
#include <iostream>
#include <string>
#include "worker.h"
using namespace std;

class Employee :public Worker
{
private:
  /* data */
public:
  Employee(int id, string name, int dId);

  virtual void showInfo();
  virtual string getDeptName();
};
