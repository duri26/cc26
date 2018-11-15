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
Base()
{
	cout<<"Base()"<<endl;
}

	private:
		int _ibase;
};

class Derived
:public Base
{
	public:
		Derived(int idreived)
			:Base()
			 ,_idreived(idreived)
			 
		{
			cout<<"Derived ()"<<endl;
		}

		void print() const
		{
			cout<<"Derived:: _idreived  "<<_idreived<<endl;
		}

	private:
		int _idreived;
};

int main(void)
	{
		Derived d(100);
		d.print();

		return 0;
	}
