#include <iostream>
#include<string>
using std::cout;
using std::cin;
using std::getline;
using std::endl;
using std::string;


int main() {
  // string line;
  // while (getline(cin, line)) {
  //   cout << line << endl;
  // }

  // string s1 = "hello, ", s2 = "world\n";
  // string s3 = s1 + s2;
  // s1 += s2;
  // cout << s3 << endl;
  // cout << s1 << endl;
  // for (string str; getline(cin, str); cout << str << endl);
  // return 0;
  // for (string str; cin >> str; cout << str << endl);
  // return 0;
  // string str1, str2;
  // cin >> str1 >> str2;
  // if (str1.size() == str2.size()) {
  //   cout << "equal" << endl;
  // } else if (str1.size() > str2.size()) {
  //   cout << str1 << endl;
  // } else {
  //   cout << str2 << endl;
  // }

  // string str("some string!");
  // decltype(str.size()) punct_cnt = 0;
  // for (auto c : str) {
  //   if (ispunct(c)) {
  //     ++punct_cnt;
  //   }
  // }
  // cout << punct_cnt
  //      << endl;
  // string str("some string!");
  // for (auto &c : str) {
  //   c = toupper(c);
  // }
  // cout << str << endl;
  string str;
  cin >> str;
  for (char &c : str) {
    c = 'X';
  }
  cout << str << endl;
  return 0;
}
