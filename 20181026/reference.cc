 ///
 /// @file    reference.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-10-26 20:55:33
 ///
 
#include <iostream>
using std::cout;
using std::endl;

void test0()
{
	int number=1;
	cout <<"number="<<number<<endl<<endl;

	int &ref=number;

	ref=10;
	cout<<"&ref="<<&ref<<endl;
cout<<"&number="<<&number<<endl<<endl;
cout<<"number="<<number<<endl;
cout<<"ref="<<ref<<endl;

//int * p1=NULL;

const int &ref2=10;
cout<<"ref2="<<ref2<<endl;
}

int main()
	{
		test0();
		return 0;
	}

