 ///
 /// @file    static_cast.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-10-26 21:11:20
 ///
#include <stdlib.h> 
#include <iostream>
using std::cout;
using std::endl;

void test0()
{
	double dvalue=11.11;
	int number=(int)dvalue;
	int number2=int(dvalue);

cout<<"number="<<number<<endl;
cout<<"number2="<<number2<<endl;
}

void test1()
{
double dvalue=11.11;
int number=static_cast<int>(dvalue);
cout<<endl<<"number="<<number<<endl;
}

void test2()
{
	int *p1=static_cast <int*>(malloc(sizeof(int)));
	*p1=10;
	free(p1);
p1=NULL;
}

int main()
{
	test0();
	test1();
	test2();
	return 0;
}
