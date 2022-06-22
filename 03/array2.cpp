#include<iostream>

using namespace std;
int main() {
  int arr[] = {0, 1, 2, 3, 4, 5};
  for (auto *a = begin(arr); a != end(arr); a++)
  {
    cout << a << endl;
  }
  
  return 0;
}