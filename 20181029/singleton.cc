 ///
 /// @file    singleton.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-10-30 08:54:12
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class singleton
{
	public:
		static singleton * getinstance()
		{
			if(NULL==_pinstance)
			{
				_pinstance=new singleton();
			}
			return _pinstance;
		}

		static void destroy()
		{
			if(_pinstance)
			{
				delete _pinstance;
			}
		}

	private:
		singleton()
		{
			cout<<"singleton()"<<endl;
		}
		~singleton()
		{
			cout<<"~singleton()"<<endl;
		}

	private:
		static singleton * _pinstance;
};

singleton * singleton::_pinstance=NULL;

int main(void)
{

	singleton *p1=singleton::getinstance();
	singleton *p2=singleton::getinstance();
cout<<"p1="<<p1<<endl;
cout<<"p2="<<p2<<endl;

singleton::destroy();

return 0;
}