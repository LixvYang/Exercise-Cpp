#include <iostream>
using namespace std;

class Animal
{
  public:
    void speak() {
       cout << "动物在说话" << endl;
    }
};

// 猫类
class Cat :public Animal
{
public:
  void speak()
  {
    cout << "猫类在说话" << endl;
  }
};

void doSpeak(Animal &animal)
{
  animal.speak();
}

void test01()
{
  Cat cat;
  doSpeak(cat);
}

int main()
{
  test01();
  return 0;
}