 ///
 /// @file    overload.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-10-26 20:32:26
 ///
 
#include <iostream>
using std::cout;
using std::endl;

int add(int x,int y)
{
	return x+y;
}

int add(int x,int y,int z)
{
	return x+y+z;
}

int main()
	{
		int a=2,b=3,c=4;
		printf("a+b=%d\n",add(a,b));
		printf("a+b+c=%d\n",add(a,b,c));

		return 0;
	}:
