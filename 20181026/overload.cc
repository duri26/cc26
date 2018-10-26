 ///
 /// @file    overload.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-10-26 20:39:54
 ///
#include <stdio.h>

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

double add(double x,double y)
	{
		return x+y;
	}

int add(double x,int y)
{
	return x+y;
}

int add(int x,double y)
{
	return x+y;
}

int main()
{
	int a=3,b=6,c=9;
	printf("a+b=%d\n",add(a,b));
	printf("a+b+c=%d\n",add(a,b,c));

	return 0;
}
