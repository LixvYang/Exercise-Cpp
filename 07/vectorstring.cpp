#include <iostream>
#include <string>
#include <vector>
using namespace std;

void test01()
{
  string s1;

  const char *str = "Hello World";
  string s2(str);

  cout << "S2= " << s2 << endl;

  string s3(s2);
  cout << "S3= " << s3 << endl;

  string s4(10, 'a');
  cout << "S4= " << s4 << endl;
}

int main()
{
  test01();
  return 0;
}