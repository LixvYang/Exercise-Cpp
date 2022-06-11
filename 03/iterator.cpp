#include <iostream>
#include <string>
#include<vector>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

int main() {
  // auto b = v.begin(), e = v.end();
  // vector<string> s{"some string"};
  // string s = "some string";
  // if (s.begin() != s.end()) {
  //   auto it = s.begin();
  //   *it = toupper(*it);
  // }
  // cout << s << endl;

  // for (auto it = s.begin(); it != s.end() && !isspace(*it); ++it)
  // {
  //   *it = toupper(*it);
  // }
  // cout << s << endl;
  // vector<int> s(10, 2);
  // for (auto it = s.begin(); it != s.end(); ++it) {
  //   *it *= 2;
  //   cout << *it << " ";
  // }


  // for (auto it = s.cbegin(); it != s.cend() && !it.empty(); ++it)
  // {
  //   *it = toupper(*it);
  //   cout << *it << endl;
  // }

  // auto mid = vi.begin() + vi.size()/2;
  
  auto beg = text.begin(), end = text.end();
  auto mid = text.begin() + text.size()/2;
  while (mid != end && *mid != sought)
  {
    if (sought < *mid) {
      end = mid;
    } else {
      beg = mid;
    }
    mid = beg + (end - beg)/2;
  }
  

  return 0;
}