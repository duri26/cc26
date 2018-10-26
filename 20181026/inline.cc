 ///
 /// @file    inline.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-10-26 22:24:29
 ///
 
#include <iostream>
using std::cout;
using std::endl;

#define MAX(x,y)  ((x)>(y)?(x):(y))
#define Mul(x,y) x*y

inline int max(int x,int y)
{
	return x>y?x:y;
}

inline int mul(int x,int y)
{
	return x* y;
}

int test0()
{
	int a=3,b=8;
	cout<<MAX(a,b)<<endl;

	cout<<Mul(3+5,4)<<endl;
	cout<<max(a,b)<<endl;
	cout<<mul(3+5,4)<<endl;
}

int main()
{
test0();
return 0;
}
