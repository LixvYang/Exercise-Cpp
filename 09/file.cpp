#include <iostream>
#include <istream>
#include <string>
#include <fstream>
using namespace std;

istream &func(istream &is)
{
  string buf;
  while (is >> buf)
  {
    cout << buf << endl;
  }
  is.clear();
  return is;
}

void test01()
{
  const string book = "book.txt"; 
  ifstream in(book);
  in.close();
  ofstream out;
  out.open(book + "copy");
  out.close();
}

int main()
{
  // istream &is = func(cin);
  // cout << is.rdstate() << endl;
  test01();
  return 0;
}
