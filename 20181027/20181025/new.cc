 ///
 /// @file    new.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-10-27 15:04:44
 ///
#include <stdlib.h>
#include <string.h>

#include <iostream>
using std::cout;
using std::endl;

void test0()
{
	int *p0=(int*)malloc(sizeof(int));
	memset(p0,0,sizeof(int));
	*p0=10;
	cout<<"malloc-->*p0="<<*p0<<endl;
int *p1=(int*)malloc(sizeof(int)*10);
for(size_t idx=0;idx<10;++idx)
{
	p1[idx]=idx;
	cout<<"p1[idx]="<<p1[idx]<<endl;
}
free(p0);
free(p1);
p0=NULL;
p1=NULL;
}

void test1()
{
	int *p0=new int(10);
	cout<<"*p0="<<*p0<<endl;
delete p0;

int *p1=new int[10];
for(size_t idx=0;idx!=10;++idx)
{
	p1[idx]=idx;
	cout<<"p1[idx]="<<p1[idx]<<endl;
}
delete []p1;
}

int main()
	{
		test0();
		test1();
		return 0;
	}

