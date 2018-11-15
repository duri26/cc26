 ///
 /// @file    multiderived3.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-15 16:29:41
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class A 
{
	public:
		void show () const
		{
			cout<<"a:: show()"<<_dx<<endl;
		}

		void setX(double dx)
		{
			_dx = dx;
		}

	private:
		double _dx;
};

class B
:virtual public A
{
	private:
double _db;
};

class C
: virtual public A
{	
	private:
double _dc;
};

class D 
:public B,public C
{
	private:
		double _dd;
};

int main(void)
{
	D d;
	d.setX(999.333);

	d.show();

	return 0;
}
