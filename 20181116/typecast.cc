 ///
 /// @file    typecast.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-17 17:06:43
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Base
{
	public:
		Base(int ix)
			: _ibase(ix)
		{
			cout<<"Base (int)"<<endl;
		}

		void print() const
		{
			cout<<"_ibase = "<<_ibase<<endl;
		}

		~Base()
		{
			cout<<"~Base ()"<<endl;
		}

	protected:
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
		cout<<"Derived(int ,int )"<<endl;
	}

		void display() const 
		{
			cout<<"_iderived = "<<_iderived<<endl;
		}

		~Derived()
		{
			cout<<"~_Derived()"<<endl;
		}

	private:
		int _iderived;
};


int main(void)
{
	Base base(11);
	Derived derived(1, 10);

	//Base & operator=(const Base & rhs);
	base = derived;//base.operator=(derived);

	//Derived & operator=(const Derived & rhs)
	//derived = base;//error 

	Base * pbase = &base;

	pbase = &derived;//向上转型
	pbase->print();

//	Derived * pderived = &base;//向下转型,比较危险
//	pderived->display();

	Base & baseref = base;

	Base & baseref2 = derived;
	return 0;
}

