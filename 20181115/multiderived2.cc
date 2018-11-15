 ///
 /// @file    multiderived2.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-15 16:15:05
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class A
{
	public:
		void show()const
		{
			cout<<"a ::show()"<<endl;
		}
};

class B
{
	public:
		void show ()const
		{
			cout<<"b ::show()"<<endl;
		}
};

class C
{
	public:
		void show () const
		{
			cout<<"c :: show()"<<endl;
		}
};

class D
:public A,public B,public C
{
};

int main(void)
{
	D g;
	g.A::show();
	g.B::show();
	g.C::show();


	return 0;
}
