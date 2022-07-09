#include <iostream>
using namespace std;

class CPU 
{
  public:
  virtual void calculate() = 0;
};

class VideoCard
{
  public:
  virtual void display() = 0;
};

class Memory
{
  public:
  virtual void storage() = 0;
};

class Computer
{
public:
  Computer(CPU * cpu, VideoCard * vc, Memory * mem)
  {
    this->m_cpu = cpu;
    this->m_vc = vc;
    this->m_mem = mem;
  }
  void work()
  {
    m_cpu->calculate();
    m_vc->display();
    m_mem->storage();
  }
  ~Computer()
  {
    if (m_cpu != NULL) 
    {
      delete m_cpu;
      m_cpu = NULL;
    }
    if (m_vc != NULL) 
    {
      delete m_vc;
      m_vc = NULL;
    }
    if (m_mem != NULL) 
    {
      delete m_mem;
      m_mem = NULL;
    }
  }

private:
  CPU * m_cpu;
  VideoCard * m_vc;
  Memory * m_mem;
};

class IntelCPU :public CPU
{
public:
  virtual void calculate()
  {
    cout << "Intel 的CPU开始工作了! " << endl;
  }
};
class IntelMemory :public Memory
{
public:
  virtual void storage()
  {
    cout << "Intel 的内存开始工作了! " << endl;
  }
};

class IntelVC :public VideoCard
{
public:
  virtual void display()
  {
    cout << "Intel 的显卡开始工作了! " << endl;
  }
};

// Lenovo
class LenovoCPU :public CPU
{
public:
  virtual void calculate()
  {
    cout << "Lenovo 的CPU开始工作了! " << endl;
  }
};
class LenovoMemory :public Memory
{
public:
  virtual void storage()
  {
    cout << "Lenovo 的内存开始工作了! " << endl;
  }
};

class LenovoVC :public VideoCard
{
public:
  virtual void display()
  {
    cout << "Lenovo 的显卡开始工作了! " << endl;
  }
};

void test01()
{
  CPU * interCPU = new IntelCPU();
  VideoCard * intelVC = new IntelVC();
  Memory * interMem =  new IntelMemory();

  Computer * computer1 = new Computer(interCPU, intelVC, interMem);
  computer1->work();
  delete computer1;
};

int main()
{
  test01();
  return 0;
}
