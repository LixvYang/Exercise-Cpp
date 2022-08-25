#include <string>
#include <iostream>
using namespace std;

int main()
{
   string s = "abc123456";

    string::iterator it = s.begin();  //定义迭代器变量，指向字符串对象首元素；

    s.erase(it+3);   //删除第三个元素，元素从位置0开始计数；

    cout << s << endl;

    s.erase(it, it+4);  //删除区间[0, 4)内所有元素的值；

    cout << s << endl;

    s = "";   //清空字符串，或者直接用s.clear()；

    cout << s.length() << endl;  //输出字符串的长度；

    return 0;
}
