 ///
 /// @file    empty.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-07 20:16:45
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Computer
{
	private:
static  char a;//静态数据成员位于全局/静态区, 不会占据对象的空间
		char * _brand;
		float _price;
};

class Empty
{};

int main(void)
{
	Computer C;
	cout<<"sizeof(&Computer)="<<sizeof(&C)<<endl;//64位 地址8字节
	cout<<"sizeof(Computer)="<<sizeof(Computer)<<endl; //类空间的大小，字节对齐


	cout<<"sizeof(Empty)="<<sizeof(Empty)<<endl;

	Empty e1,e2;
	cout<<&e1<<endl;
	cout<<&e2<<endl;// 一次最少最小地址
	// 有疑问 字节是计算机中数据处理的基本单位。计算机中以字节为单位存储和解释信息，规定一个字节由八个二进制位构成，即1个字节等于8个比特（1Byte=8bit）

	return 0;
}

