 ///
 /// @file    virtual1.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-16 20:00:30
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Base
{
	public:
		Base(double dbase = 0)
			: _dbase(dbase)
		{
			cout<<"Base (double)"<<endl;
		}

		virtual
			void func()
			{
				cout<<"Base::func() _dbase = "<<_dbase<<endl;
			}

	private:
		double _dbase;
};

class Derived
:public Base
{
	public:
		Derived(double dbase,double dderived)
			:Base(dbase)
			 ,_dderived(dderived)
	{
		cout<<"Derived(double,double)"<<endl;
	}

		void func()
		{
			cout<<"Derived::func() _dderived = "<<_dderived<<endl;
		}

	private:
		double _dderived;
};

class Derived2
:public Base
{
	public:
		Derived2(double dbase,double dderived)
			:Base(dbase)
			 ,_dderived(dderived)
	{
		cout<<"Derived2(double ,double )"<<endl;
	}

		void func()
		{
			cout<<"Derived2(double ,double) _dderived = "<<_dderived<<endl;

		}

	private:
		double _dderived;
};

void display(Base * phase)
{
	phase->func();
	}

int test0()
{
	Derived d(1,10);
	d.func();

	Derived2 d2(11,22);
	cout<<endl;

	display(&d);
	display(&d2);
	cout<<endl;

	cout<<"基类引用绑定到派生对象"<<endl;

	Base & ref = d;
	ref.func();

Base & re =  d2;
re.func();
	return 0;
}

void test1()
{
	cout<<endl<<"sizeof(Base) = "<<sizeof(Base) <<endl;
}


int main(void)
{
	test0();
test1();
	return 0;
}
