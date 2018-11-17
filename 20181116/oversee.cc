 ///
 /// @file    oversee.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-16 14:22:01
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Base
{
	public:
		Base(int ix)
			: _ix(ix)
		{
			cout<<"Base(int )"<<endl;
		}

		int func()
		{
			cout<<"Base::func()"<<endl;
			return _ix;
		}

		~Base()
		{
			cout<<"~Base()"<<endl;
		}

	protected:
		int _ix;
};


class Derived
:public Base
{
	public:
		Derived(int ibase,int iderived)
		:Base(ibase)
		 ,_ix(iderived)
	{
		cout<<"Derived(int,int)"<<endl;
	}

		int func()
		{
			cout<<"Base::_ix ="<<Base::_ix<<endl;
			cout<<"Derived::_ix ="<<_ix<<endl;

			return _ix;
		}

		~Derived()
		{
			cout<<"~Derived()"<<endl;
			}

	private:
		int _ix;
};

int main(void)
{
	Derived d(1,22);

	cout<<d.Base::func()<<endl;

	cout<<d.func()<<endl;

	return 0;
}
