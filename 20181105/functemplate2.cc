 ///
 /// @file    functemplate2.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-05 23:43:20
 ///
 
#include <iostream>
using std::cout;
using std::endl;

template <typename T,char kNumber=1>
T multiply(T x)
{
	return x * kNumber;
}

int main(void)
{
	int a1=10;
	cout<<"multiply(a1)="<<multiply<int,10>(a1)<<endl;
	cout<<"multiply(a1)="<<multiply(a1)<<endl;
return 0;
}
