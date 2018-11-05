 ///
 /// @file    autorelesesingleton.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-04 22:26:40
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Singleton
{
	class AutoRelease
	{
		public:
			AutoRelease()
			{
				cout << "AutoRelease()"<<endl;
}

~AutoRelease()
{
	cout<<"~AutoRelease()"<<endl;
		if(_pInstance)
	{
		delete _pInstance;
		cout<<"delet _pInstance;"<<endl;
	}
	}
};

public:
static Singleton * getInstance()
{
	if(NULL ==_pInstance)
	{
		_pInstance = new Singleton;
	}
	return _pInstance;
}

static void destroy()
{
	if(_pInstance)
	{
		delete _pInstance;
	}
}

private:
Singleton()
{
	cout<<"Singleton()"<<endl;
}

~Singleton()
{
	cout<<"~Singleton()"<<endl;
}

private :
static AutoRelease _ar;
static Singleton * _pInstance;
};

Singleton::AutoRelease Singleton ::_ar;
Singleton * Singleton ::_pInstance =getInstance();

int main(void)
{
	Singleton *p1=Singleton ::getInstance();
	Singleton *p2=Singleton ::getInstance();
cout<<"p1="<<p1<<endl;
cout << "p2="<<p2<<endl;

return 0;
}
