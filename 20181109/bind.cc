///
/// @file    bind.cc
/// @author  duri(1197010670@qq.com)
/// @date    2018-11-10 19:47:42
///
#include <functional> 
#include <iostream>
using std::cout;
using std::endl;
using std::bind;

void display()
{
	cout<<"display()"<<endl;
}

void print()
{
	cout<<"print()"<<endl;
}

void test0()
{
	typedef void (*Function)();
	Function f1 = display;
	f1();

	f1 = print;
	f1();
}

int add(int x,int y)
{
	return x + y;
}

struct Mytest
{
	int add(int x,int y)
	{
		return x + y;
	}
	int _data = 100;
};


void test1()
{
	using namespace std::placeholders;
	auto f1=std::bind(add,10,_1);
	cout<<"f1="<<f1(20)<<endl;

	auto f2 = std::bind(add,_1,_2);
	cout<<"f2="<<f2(10,20)<<endl;

	auto f3 = std::bind (add,11,22);
	cout<<"f3="<<f3()<<endl;

	Mytest test;
	auto f4 = std::bind(&Mytest::add, &test, 10, _1);
	cout << ">> 绑定成员函数测试：" << endl; 
	cout << "f4 = " << f4(20) << endl;

	auto f5 = std::bind(&Mytest::add, test, 10, _1);
	cout << "f5 = " << f5(20) << endl;

	auto f6 = std::bind(&Mytest::_data, test);
	cout << "f6 = " << f6() << endl;
}

void func(int n1, int n2, const int & n3, int n4)
{
	cout << "(" << n1 
		<< "," << n2
		<< "," << n3
		<< "," << n4
		<< ")" << endl;
}
int main(void)
{
	test1();


	return 0;
}
