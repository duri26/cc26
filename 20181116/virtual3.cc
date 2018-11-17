 ///
 /// @file    virtual3.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-16 20:54:20
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Base
{
	public:
		Base()
		{
			cout<<"Base()"<<endl;
		}

		virtual void func1()
		{
			cout<<"Base ::func1()"<<endl;
		}
		virtual void func2()
		{
			cout<<"Base::func2()"<<endl;
		}

		~Base()
		{
			cout<<"~Base()"<<endl;
		}
};

class Child
:public Base
{
	public:
		Child()
		{
			cout<<"Child()"<<endl;
			func1();
		}

		virtual void func1() 
		{
			cout<<"Child::func1()"<<endl;
		}
		virtual void func2()
		{
			cout<<"Child::func2()"<<endl;
		}


		~Child()
		{
			cout<<"~Child()"<<endl;
			func1();
		}
};

class Derived
:public Child
{
public:
	Derived()
		:Child()
	{
		cout<<"Derived()"<<endl;
	}

	virtual void func1()
	{
		cout<<"Derived::func1()"<<endl;
	}
	virtual void func2()
	{
		cout<<"Derived::func2()"<<endl;
	}

	~Derived()
	{
		cout<<"~Derived()"<<endl;
	}

};

int main(void)
{
	Derived d;

	Base * phase = &d;
	cout<<endl;

	phase->func1();
	phase->func2();
	cout<<endl;

	return 0;
}
