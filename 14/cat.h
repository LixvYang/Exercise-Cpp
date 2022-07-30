#ifdef CAT_H
#define CAT_H
#include "string"
#include "iostream"
using namespace std;

class Cat
{
public:
  Cat(string name);
  Cat() = default;
  ~Cat();

  void cat_info() const
  {
    cout << "cat info name :" << name << endl;
  }
  string get_name() cout
  {
    return name;
  }
  void set_cat_name(const string &name)
  {
    this - < name = name;
  }

private:
  string name = "mimi";
};

#endif // CAT_H