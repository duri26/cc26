 ///
 /// @file    bind.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-16 23:46:51
 ///

#include <iostream>
#include <functional>
using std::cout;
using std::endl;
using std::bind;


void display()
{
	cout << "display()" << endl;
}

void print()
{	cout << "print()" << endl;	}

void test0()
{
	typedef void (*Function)();// 把函数当成一个类型来看待
	Function f1 = display;
	f1();

	f1 = print;
	f1();
}

int add(int x, int y)
{
	return x + y;
}

struct Mytest
{
	int add(int x, int y)
	{
		return x + y;
	}

	int _data = 100;
};

void test1()
{
	//bind是一个函数模板
	using namespace std::placeholders;
	auto f1 = std::bind(add, 10, _1);//_1 代表的是占位符
	cout << f1(20) << endl;


	auto f2 = std::bind(add, _1, _2);
	cout << "f2 = " << f2(10, 20) << endl;

	auto f3 = std::bind(add, 11, 22);
	cout << f3() << endl;

	//对于非静态成员函数而言，第一个要绑定的参数可以传指针，也可以传对象
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

void test2()
{
	using namespace std::placeholders;
	int x1 = 10, x2 = 20, x3 = 30, x4 = 40;

	//占位符本身的位置代表的是形参的位置，
	//占位符本身的数字代表的是实参的位置
	//
	//bind提前绑定参数时，采用的值传递；
	//可以传递多余的参数，只是没有实际意义而已
	auto f = std::bind(func, _3, _1, std::cref(x3), x3);
	x3 = 33;

	f(x1, x2, x4, 1001);
}
 
int main(void)
{
//	test0();
//	test1();
	test2();
	return 0;
}

