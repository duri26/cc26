 ///
 /// @file    new.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-10-25 23:47:23
 ///
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <iostream>
using std::cout;
using std::endl;

void test0()
{
	int *p1=(int*)malloc(sizeof(int));
	memset(p1,0,sizeof(int));
	*p1=10;
	cout<<"malloc -->*p1 = "<<*p1<<endl;

	int *p2=(int*)malloc(sizeof(int)*10);
	for(size_t idx=0;idx!=10;++idx)
		p2[idx]=idx;
	free(p1);
}


void test1()
{
	int *p1=new int(10);
	cout<<"new->*p1="<<*p1<<endl;
	delete p1;

	int *p2=new int[10];
	for(size_t idx=0;idx!=10;++idx)
	{
		p2[idx]=idx;
		cout <<p2[idx]<<endl;
	}
	delete []p2;
}
int main()
{
//	test0();
test1();
}
