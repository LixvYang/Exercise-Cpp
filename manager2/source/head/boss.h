#pragma once
#include <iostream>
#include <string>
#include "worker.h"
using namespace std;

class Boss :public Worker
{
private:
public:
  Boss(int id, string name, int dId);

  virtual void showInfo();
  virtual string getDeptName();
};
