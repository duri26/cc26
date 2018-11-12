 ///
 /// @file    computer.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-07 22:17:32
 ///
#include <string.h> 
#include <iostream>
using std::cout;
using std::endl;

class Computer
{
public:
	Computer(const char * brand, float price)
	: _brand(new char[strlen(brand) + 1]())
	, _price(price)
	{
		strcpy(_brand, brand);
		cout << "Computer(const char*, float)" << endl;
	}

#if 0
	//编译器自动提供的复制构造函数 不再满足需求
	Computer(const Computer & rhs)
	: _brand(rhs._brand) //地址传递 => 浅拷贝
	, _price(rhs._price)
	{
		cout << "Computer(const Computer &)" << endl;
	}
#endif

	Computer(const Computer & rhs)
	: _brand(new char[strlen(rhs._brand) + 1]()) //地址传递 => 浅拷贝
	, _price(rhs._price)
	{
		strcpy(_brand, rhs._brand);// 深拷贝
		cout << "Computer(const Computer &)" << endl;
	}

	
#if 0
	//此时编译器提供的赋值运算符函数不能满足实际的需要，必须
	//重新编写
	Computer & operator=(const Computer & rhs)
	{
		cout << "Computer & operator=(const Computer&)" << endl;
		_brand = rhs._brand;
		_price = rhs._price;
		return *this;
	}
#endif

#if 1
	Computer & operator=(const Computer & rhs)
	{
		cout << "Computer & operator=(const Computer&)" << endl;
		if(this != &rhs) // 1. 自复制
		{
			delete [] _brand;//2. 回收左操作数申请的空间

			_brand = new char[strlen(rhs._brand) + 1]();//3. 深拷贝
			strcpy(_brand, rhs._brand);

			_price = rhs._price;
	}
		return *this;
	}
#endif
	//析构函数可以显式调用，但调用析构函数并不代表对象被销毁了；
	//如果对象被销毁，一定会调用析构函数
	~Computer()
	{
		delete [] _brand;
		cout << "~Computer()" << endl;
	}

	void print() 
	{
		cout << "品牌:" << _brand << endl
			 << "价格:" << _price << endl;
	}
	
private:
	char * _brand;
	float _price;
};


int main(void)
{
	Computer pc1("zhanshen", 9999);//堆对象
	cout << "pc1 = " ;
	pc1.print();

	Computer pc2("Xiaomi", 7777);//调用复制构造函数
	cout << "pc2 = ";
	pc2.print();

	pc2 = pc1;
	cout << "pc2 = " ;
	pc1.print();

	pc1 = pc1;

	return 0;
}
