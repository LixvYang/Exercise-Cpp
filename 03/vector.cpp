#include <iostream>
#include <string>
#include<vector>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

int main() {
  // vector<int> ivec;
  // vector<Sales_item> Sales_vec;
  // vector<vector<string>> file;
  // vector<int> ivec;
  // vector<int> ivec2(ivec);
  // vector<int> ivec3 = ivec;
  // // vector<string> svec(ivec2)  // 错误
  // vector<string> articles = {"a", "an", "the"};

  // vector<int> ivec(10, 01);
  // vector<string> svec(10, "hi!");

  // vector<int> vi = {10};
  // vector<int> v2;
  // for (int i = 0; i != 100; ++i)
  // {
  //   v2.push_back(i);
  // }
  
  // string word;
  // vector<string> text;
  // while (cin >> word) {
  //   text.push_back(word);
  // }

  // vector<int> ivec;
  // for (int i; cin >> i; ivec.push_back(i));
  // vector<string> vec;
  // for (string buffer; cin >> buffer; vec.push_back(buffer));
  vector<int> v{1,2,3,4,5,6,7,8,9};
  for (auto &i : v) 
    i *= i;
  
  for (auto i : v) 
    cout << i << " ";

  cout << endl;

  return 0;
}

