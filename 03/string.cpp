#include<iostream>
#include<string>
using std::string;
using std::cout; 
using std::cin; 
using std::endl;

int main() {
  // string s1;
  // string s2 = s1;
  // string s3 = "Hiya";
  // string s4(10, 'c');

  // cout << s1 << endl;
  // cout << s2 << endl;
  // cout << s3 << endl;
  // cout << s4 << endl;

  string s;
  getline(cin, s);
  cout << s.size() << endl;
  return 0;

  // vim code
  for (i = 0; i < 10; ++i) {
    if (i % 2 == 1) {
      cout << i << endl; 
    }
  }

  
}
