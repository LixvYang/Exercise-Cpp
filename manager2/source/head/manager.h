#pragma once
#include <iostream>
#include <string>
#include "worker.h"
using namespace std;

class Manager :public Worker
{
private:
public:
  Manager(int id, string name, int dId);

  virtual void showInfo();
  virtual string getDeptName();
};
