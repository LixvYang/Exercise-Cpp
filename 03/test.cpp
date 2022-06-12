#include <iostream>
 
using namespace std;
 
//by zhaocl
int main()
{
    int ia[5] = { 1, 2, 3, 4, 5 };
 
	//利用begin、end函数修改元素值
    for( int *p = begin( ia ); p != end( ia ); p++ )
    {
        *p = 0;
    }
 
    for( auto i : ia )
    {
        cout << i << endl;
    }
 
    system( "pause" );
    return 0;
}
