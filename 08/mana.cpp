#include <ctime>
#include <iostream>
#include <map>
#include <ostream>
#include <utility>
using namespace std;
#include <string>
#include <vector>

#define CHEUA 0
#define MEISHU 1
#define YANFA 2

class Worker
{
public:
  string m_Name;
  int m_Salary;
};

void createWorker(vector<Worker>& v)
{
  string nameSeed = "ABCEDFGHIJ";
  for (int i = 0; i < 10; i++)
  {
    Worker workder;
    workder.m_Name = "员工";
    workder.m_Name += nameSeed[i];
    workder.m_Salary = rand() % 10000 + 10000; // 10000 - 19999
    v.push_back(workder);
  }
}

void setGroup(vector<Worker>&v, multimap<int, Worker>&m)
{
  for (auto it = v.begin(); it != v.end(); it++)
  {
    int deptId = rand()%3;

    m.insert(make_pair(deptId, *it));
  }
}

void showWorkerByGroup(multimap<int, Worker> &m)
{
  cout << "策划部门： " << endl;
  multimap<int, Worker>::iterator pos = m.find(CHEUA);
  int count = m.count(CHEUA);
  int index = 0;
  for(; pos != m.end() && index < count; pos++, index++)
  {
    cout << "Name:  " << pos->second.m_Name << " Salary: " << pos->second.m_Salary << endl;
  }
  cout << "------------" << endl;
  cout << "美术部门" << endl;
  pos = m.find(MEISHU);
  count = m.count(MEISHU);
  index = 0;
  for(; pos != m.end() && index < count; pos++, index++)
  {
    cout << "Name:  " << pos->second.m_Name << " Salary: " << pos->second.m_Salary << endl;
  }
  cout << "------------" << endl;
  cout << "研发部门" << endl;
  pos = m.find(YANFA);
  count = m.count(YANFA);
  index = 0;
  for(; pos != m.end() && index < count; pos++, index++)
  {
    cout << "Name:  " << pos->second.m_Name << " Salary: " << pos->second.m_Salary << endl;
  } 
}
int main()
{
  srand((unsigned int)time(NULL));
  vector<Worker> vWorker;
  createWorker(vWorker);
  multimap<int, Worker> mWorker;
  setGroup(vWorker, mWorker);
  showWorkerByGroup(mWorker);
  //  for (vector<Worker>::iterator it = vWorker.begin(); it != vWorker.end(); it++)
  // {
  //   cout << "Name: " << it->m_Name << " salary: " << it->m_Salary << endl;
  // }
  return 0;
}
