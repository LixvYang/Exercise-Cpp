#include<iostream>
#include<vector>
#include<string>
#include<cstring>
using std::string;
using std::cout; 
using std::cin; 
using std::endl;
using std::vector;
using namespace std;

int main(){
  // unsigned cnt = 42;
  // onstexprigned sz= 42;
  // cnt arr[10];
  // int *pazz[sz];
  // string bad[cnt]; // 错误
  // string strs[get_size()];  当get_size是constexpr的时候是正确;

  // unsigned scores[11] = {};
  // unsigned grade;
  // while (cin >> grade) {
    // if (grade <= 100)
      // ++scores[grade/10]
  // }

  // int arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }; 
  // int arr[10];
  // for (int i = 1; i < 10; ++i) arr[i] = i;
  // int arr2[10];
  // for (int i = 2; i < 10; ++i) arr2[i] = arr[i];

  // vector
  // vector<int> v(10);
  // for (int i = 1; i < 10; ++i) v[i] = arr[i];
  
  // vector<int> v2(v);
  // for (auto i : v2) cout << i << " ";
  // cout << endl;
  

  // int a[] = {0, 1, 2};
  // int a2[10];
  // a2 = a; // 错误;
  // for (auto i : scores)
    // std::cout << i + " " << std::endl;

  // string nums[] = {"one", "two", "three"};
  // string *p = &nums[0];
  // string *p2 = nums; // 于上面一样 p2 = &nums[0];
  // int ia [10];
  // for (int i = 0; i < 10; ++i) ia[i] = i;
  // auto ia2 = ia; // ia2 是指向ia[0]的地址
  // cout << ia << endl;
  // cout << &ia[0] << endl;
  // decltype(ia) ia3 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  // ia3 = p;
  // ia3[4] = i;
  // cout << ia3 << endl;
  /* int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; */
  /* int *p = arr; */
  /* int *e = &arr[10]; */
  /* for (int *b = arr; b != e; ++b)  */
    // cout << *b << endl;
  // const int size = 10;
  // int arr[size];
  // for (auto ptr = arr; ptr != arr + size; ++ptr) *ptr = 0;
  
  // for (auto i : arr) cout << i << " ";
  // cout << endl;

  // for (int *b = begin( arr ); b != end (arr ); b++} {
    // *b = 0;
  // }

  // for(int *p = begin(arr); arr != end(arr); p++)
  // {
      // *p = 0;
  // }

  // for (auto i : arr) cout << i << endl;

  // char ca[] = {'C', '+', '+', '\n'};
  // char s1[] = "Hello, C++";
  // char s2[] = "Hello, C+";
  // cout << strlen(ca) << endl;

  // int result = strcmp(s1, s2);
  // cout << result << endl;
  // if (result == 0) {
    // cout << "Strings are equal" << endl;
  // } else {
    // cout << "Strings are unequal, result is" << endl;
  // }

  
  return 0;
}
