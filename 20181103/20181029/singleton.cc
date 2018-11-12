 ///
 /// @file    singleton.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-06 23:24:05
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class singleton
{
	public:
		static singleton * getinstance()
		{
			if(NULL == _pinstance)
			{
				_pinstance =new singleton();
			}
return _pinstance;
		}

		static void destroy()
		{
	if(_pinstance)
			delete _pinstance;
		}

	private:
		singleton()
		{
			cout<<"singleton ()"<<endl;
		}

		~singleton()
		{
			cout<<"~singleton()"<<endl;
		}

		static singleton * _pinstance;
};

singleton * singleton::_pinstance;

int main(void)
{
singleton * p1=	singleton ::getinstance ();
singleton * p2=	singleton ::getinstance ();

cout<< "1    "<<p1<<endl;
cout<< "2    "<<p1<<endl;

return 0;
}
