#include<iostream>
void simple();
int bigger();


int main() {
  using namespace std;
  cout << "main() will call the simple() function: \n";
  simple();
  cout << "main() finished with the simple() function: \n";
  return 0;
}

void simple() 
{
  using namespace std;
  cout << "I'm but a simple function.";
}

int bigger(int a, int b) 
{
  if (a > b) {
    return a;
  } else {
    return b;
  }
}
