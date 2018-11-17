 ///
 /// @file    drivedconstruct.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-16 14:07:43
 ///
 
#include <iostream>
using std::cout;
using std::endl;
//疑问 目的是什么
class Base
{
public:
	Base(int ibase)
		: _ibase(ibase)
	{
		cout<<"Base(int)"<<endl;
	}

	~Base()
	{
		cout<<"~Base()"<<endl;
	}

	private:
	int _ibase;
};

class Foo
{
	public:
		Foo(int foo)
			: _foo(foo)
		{
			cout<<"Foo(int)"<<endl;
		}

		~Foo()
		{
			cout<<"~Foo()"<<endl;
		}

	private:
		int _foo;
};

class Derived
:public Base
{
	public:
		Derived(int iderived,int foo)
			:Base(iderived)
			 ,_iderived(iderived)
			 ,_foo(foo)
	{
		cout<<"Derived(int)"<<endl;
	}

		Derived(int ibase,int iderived,int foo)
			:Base(ibase)
			 ,_iderived(iderived)
			 ,_foo(foo)
	{
		cout<<"Derived(int ,int)"<<endl;
	}
		
		~Derived()
		{
			cout<<"~Derived()"<<endl;
		}

		void print() const
		{
			cout<<"Derived::_iderived"<<_iderived<<endl;
		}

	private:
		int _iderived;
		Foo _foo;
};

int main(void)
{
	Derived d(100,3);
	d.print();

	return 0;
}
