 ///
 /// @file    autorelesesingleton.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-04 22:26:40
 ///
#include <stdlib.h>

#include <iostream>
using std::cout;
using std::endl;

class Singleton
{


public:
static Singleton * getInstance()
{
	pthread_once(&_once,init);


	return _pInstance;
}

static void init()
{
	atexit(destroy);
	_pInstance =new Singleton;
}

static void destroy()
{
	if(_pInstance)
	{
		delete _pInstance;
cout<<"delete _pInstance3"<<endl;
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
static pthread_once_t _once;
static Singleton * _pInstance;
};

pthread_once_t Singleton::_once=PTHREAD_ONCE_INIT;

Singleton * Singleton ::_pInstance =getInstance();

int main(void)
{
	Singleton *p1=Singleton ::getInstance();
	Singleton *p2=Singleton ::getInstance();
cout<<"p1="<<p1<<endl;
cout << "p2="<<p2<<endl;

return 0;
}
