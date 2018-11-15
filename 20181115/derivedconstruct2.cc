///
/// @file    derivedconstruct1.cc
/// @author  duri(1197010670@qq.com)
/// @date    2018-11-15 14:54:44
///

#include <iostream>
using std::cout;
using std::endl;

class Base
{
	public:
#if 0
		Base()
		{
			cout<<"Base()"<<endl;
		}
#endif
		Base(int ibase=0)
			: _ibase(ibase)
		{
			cout<<"Base (int )"<<endl;
		}

	private:
		int _ibase;
};

class Derived
:public Base
{
	public:
		Derived()
			:Base()

		{
			cout<<"Derived ()"<<endl;
		}

};

int main(void)
{
	Derived d;

	return 0;
}
