#include <iostream>

using namespace std;

int main() 
{
  int array[3];
  array[0] = 7;
  array[1] = 7;
  array[2] = 7;
  
  cout << sizeof(array) << endl;
  cout << sizeof(array[1]) << endl;

  return 0;
}
