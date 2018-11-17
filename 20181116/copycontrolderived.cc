 ///
 /// @file    copycontrolderived.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-17 14:45:51
 ///
#include <string.h> 
#include <iostream>
using std::cout;
using std::endl;

class Base
{
	public:
		Base(const char * pbase)
		: _pbase(new char [strlen(pbase)+1]())
		{
			cout<<"Base(cosnt char *)"<<endl;
			strcpy(_pbase,pbase);
		}

		Base(const Base & rhs)
		:_pbase(new char [strlen(rhs._pbase)+1]())
		{
			cout<<"Base(cosnt Base &)"<<endl;
			strcpy(_pbase,rhs._pbase);
		}

		Base & operator= (const Base & rhs)
		{
			cout<<"Base & operator =(const Base &)"<<endl;
			if(this != &rhs)
			{
				delete [] _pbase;
				_pbase = new char[strlen(rhs._pbase)+1]();
				strcpy(_pbase,rhs._pbase);
			}
			return * this;
		}

		~Base()
		{
			cout<<"~Base ()"<<endl;
			delete [] _pbase;
		}

		friend std::ostream & operator <<(std::ostream & os,const Base & rhs);

	private:
		char * _pbase;
};

#if 1
std::ostream & operator <<(std::ostream & os,const Base & rhs)
{
	os <<rhs._pbase;
	return os;
}
#endif

class Derived
: public Base
{
	public:
		Derived(const char * pbase)
			:Base(pbase)
{
	cout<<"Derived(const char *)"<<endl;
}

~Derived()
{
	cout<<"~Derived()"<<endl;
}

friend std::ostream & operator<<(std::ostream & os ,const Derived & rhs);

private:
};

std::ostream & operator <<(std::ostream & os,const Derived & rhs)
{
	const Base & ref = rhs;
	os <<ref;
	return os;
}

int main(void)
{
	Derived d1("hello ");
	cout<<"d1 = "<<d1<<endl;
	Derived d2(d1);
	cout<<"d2 = "<<d2<<endl;

	cout<<endl;

	Derived d3("world");
	cout<<"d3 = "<<d3 <<endl;
	d1 = d3;
	cout<<"d1 = "<<d1<<endl;

	return 0;
}
