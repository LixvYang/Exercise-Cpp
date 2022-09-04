#include <iostream>
#include <string>
void showList(){};

using namespace std;

template <typename T>
void showList(const T &value)
{
  cout << value << '\n';
}

template <typename T, typename... Args>
void showList(const T &value, const Args &...args)
{
  cout << value << ",";
  showList(args...);
}

int main()
{
  int i = 1;
  string j = "Hello world";
  double k = 123.21321;
  showList(i, j, k);
  showList(k, j);

  auto a = []()
  {
    cout << " nihao" << endl;
  };

  []()
  {
    cout << "Hello world!" << endl;
  }();

  return 0;
}
