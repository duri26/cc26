 ///
 /// @file    destructfunc.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-16 21:31:04
 ///
#include <string.h>

#include <iostream>
using std::cout;
using std::endl;

class Base
{
	public:
		Base(const char * phase)
			: _phase(new char[strlen(phase)+1]())
		{
			cout<<"Base(int)"<<endl;
			strcpy(_phase,phase);
		}

		virtual
			void display() const
			{
				cout<<"Base: "<<_phase<<endl;
			}
		virtual ~Base()
		{
			cout<<"~Base()"<<endl;
			delete[] _phase;
		}

	private:
		char * _phase;
};

class Derived
:public Base
{
	public:
		Derived(const char * pbase,const char * pderrived)
		:Base(pbase)
		 ,_pderived(new char [strlen(pderrived)+1]())
	{
		cout<<"Derived(int ,int)"<<endl;
		strcpy(_pderived,pderrived);
	}

		virtual
			void display() const 
			{
				Base::display();
				cout<<"Derived: "<<_pderived<<endl;
			}
		~Derived()
		{
			cout<<"~Derived()"<<endl;
			delete [] _pderived;
		}

	private:
		char * _pderived;
};

int main(void)
{
	Base * phase = new Derived("hello","world");
	phase->display();

	delete phase;
	return 0;
}
