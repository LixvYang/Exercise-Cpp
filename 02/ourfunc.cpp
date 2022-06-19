// ourfunc.cpp
//
#include <iostream>
void simon(int);
using namespace std;

int main()
{
  simon(3);
  int counter;
  cin >> counter;
  simon(counter);
  cout << "Done!" << endl;
  return 0;
}

void simon(int n) 
{
  cout << n << endl;
}
