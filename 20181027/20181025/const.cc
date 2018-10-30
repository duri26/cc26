 ///
 /// @file    const.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-10-27 16:24:56
 ///


 
#include <iostream>
using std::cout;
using std::endl;

// 编写 --> 预处理 --> 编译 ---> 汇编 --> 链接 --> 可执行程序

//宏定义与const关键字的区别?
//1. 发生时机不同: 
//		宏定义发生在预处理
//		const关键字发生在编译时
//2. 宏定义就是简单的字符串替换，没有语法检查
//	 const关键字进行修饰的变量，有语法检查，可以降低错误发生的概率
#define MAX 100

void test0()
{
	cout << MAX << endl;	
}

void test1()
{
	//表达常量
	const int number = 100;
	cout << "number = " << number << endl;
	//const int number2;//error, 常量必须要进行初始化
}

//int * arr[]   vs   int (*)[]
//指针数组   vs  数组指针
//
//int * f()   vs   int (*)()
//指针函数   函数指针
//
//指针常量   vs   常量指针

void test2()
{
	//const修饰指针
	
	int number = 100;
	int number2 = 1000;
	int * p1 = &number;
	*p1 = 200;//修改所指变量的值
	p1 = &number2;//修改指针的指向
	cout << "*p1 = " << *p1 << endl;
	cout << "&number = " << &number << endl;
	cout << "&number2 = " << &number2 << endl;
	cout << "p1 = " << p1 << endl << endl;

	const int * p2 = &number;//常量指针(pointer to const)
	//*p2 = 1000;//error   不可以通过指针修改所指变量的值
	p2 = &number2;		  //可以改变指针的指向

	int const * p3 = &number;
	//*p3 = 1000;//error
	p3 = &number2;

	int * const p4 = &number;//指针常量(const pointer)
	*p4 = 1000;				 //可以通过指针修改所指变量的值
	//p4 = &number2;//error  //不可以改变指针的指向

//	const int * const p5 = &number;// 两者都不能进行修改
}
 
int main(void)
{
	//test0();
	//test1();
	test2();
	return 0;
}

