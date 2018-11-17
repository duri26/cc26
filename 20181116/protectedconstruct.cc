 ///
 /// @file    protectedconstruct.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-17 16:55:08
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Base 
{
	protected:
		Base(int ibase)
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
		Derived(int ibase,int iderived)
			: Base(ibase)
			  ,_iderived(iderived)
	{
		cout<<"Derived(int ,int)"<<endl;
	}

	private:
		int _iderived;
};

int main(void)
{
	Derived d(10,1010);

	return 0;
}
