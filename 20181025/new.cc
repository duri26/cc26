 ///
 /// @file    new.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-10-25 23:47:23
 ///
 
#include <iostream>
using std::cout;
using std::endl;

void test()
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


