 ///
 /// @file    const.c
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-10-26 19:46:30
 ///
 
#include <iostream>
using std::cout;
using std::endl;

#define M 100

void test0()
{
	cout<<M<<endl;
}

void test1()
	{
		const int number=10;
		cout <<"number ="<<number<<endl;
	}
void test2()
{
	int number=100;
	int number2=1000;
	int *p1=&number;
	*p1=200;
	p1=&number2;
	cout<<"*p1="<<*p1<<endl;
	cout<<"&number="<<&number<<endl;
	cout<<"&number2"<<&number2<<endl;
cout<<"p1="<<p1<<endl<<endl;

const int*p2=&number;
p2=&number2;

int const*p3=&number;
p3=&number2;

int *const p4=&number;
*p4=1000;
cout<<*p4<<endl;
}
int main()
{

	//test0();
//test1();
test2();
return 0; } 

