 ///
 /// @file    multiderived1.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-15 16:10:16
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class A
{
	public:
		void display() const
		{
			cout<<"A ::display()"<<endl;
		}
};

class B
{
	public:
		void print() const
		{
			cout<<"B ::print()"<<endl;
		}
};

class C
{
	public:
		void show() const 
		{
			cout<<"C ::show()"<<endl;
		}
};

class D
:public A
	,public B
	,public C
{
};

int main(void)
{
	D g;
	g.display();
	g.print();
	g.show();

	return 0;
}
