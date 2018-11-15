 ///
 /// @file    derivedconstruct3.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-15 16:37:23
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Base
{
	public:
		Base(int ibase)
			: _ibase(ibase)
		{
			cout<<"Base(int)"<<endl;
		}

	private:
		int _ibase;
};

class Derived
:public Base
{
	public:
		Derived(int iderived)
			: Base(iderived),_iderived(iderived)
		{
			cout<<"Derived(int)"<<endl;
		}

		Derived(int ibase,int iderived)
			:Base(ibase),_iderived(iderived)
		{
			cout<<"Derived(int ,int )"<<endl;
		}

		void print() const
		{
			cout<<"Derived::_iderived "<<_iderived<<endl;
		}

	private:
		int _iderived;
};

int main(void)
{
	Derived d(55,9);
	d.print();

	return 0;
}
