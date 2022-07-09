#include<iostream>
#include<string>
using namespace std;

class Calculator
{
public:
  int getResult(string oper) {
    if (oper == "+") {
      return m_Num1 + m_Num2;
    } else if (oper == "-") {
      return m_Num1 - m_Num2;
    } else if (oper == "*") {
      return m_Num1 * m_Num2;
    } 
  };

  int m_Num1;
  int m_Num2;
};

class AbstractCalculator 
{
public:
  virtual int getResult()
  {
    return 0;
  }

  int m_Num1;
  int m_Num2;
};

class AddAbstractCalculator :public AbstractCalculator
{
public:
  int getResult()
  {
    return m_Num1 + m_Num2;
  }
};

class SubAbstractCalculator :public AbstractCalculator
{
public:
  int getResult()
  {
    return m_Num1 - m_Num2;
  }
};

class MulAbstractCalculator :public AbstractCalculator
{
public:
  int getResult()
  {
    return m_Num1 * m_Num2;
  }
};

void test01()
{
  Calculator c;
  c.m_Num1 = 10;
  c.m_Num2 = 20;
  cout << c.getResult("+") << endl;
};

void test02()
{
  AbstractCalculator * abc = new MulAbstractCalculator();
  abc->m_Num1 = 10;
  abc->m_Num2 = 20;

  cout << abc->getResult() << endl;
  delete abc;
  abc = new SubAbstractCalculator();
  abc->m_Num1 = 10;
  abc->m_Num2 = 20;
  cout << abc->getResult() << endl;
  delete abc;
}


int main()
{
  test02();
  return 0;
}

