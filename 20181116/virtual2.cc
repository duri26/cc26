 ///
 /// @file    virtual2.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-16 20:25:38
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

		virtual void display()
		{
			cout<<"Base::display()"<<endl;
		}

		void func1()
		{
			this->display();
		}

		void func2()
		{
			Base::display();
		}
};

class Derived
:public Base
{
	public:
		Derived()
		{
			cout<<"Derived()"<<endl;
		}

		void display() override
		{
			cout<<"Derived:: display()"<<endl;
		}

		virtual
			void display(int x)
			{
				cout<<"形参 x = "<<x<<endl;
			}
};

int main(void)
{
	Base base;
	base.func1();
	base.func2();
	cout<<endl;

	Derived derived;
	derived.func1();
	derived.func2();

	Base * pbase = & derived;
	pbase->display();

	return 0;
}
