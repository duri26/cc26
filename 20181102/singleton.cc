 ///
 /// @file    Singleton.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-02 14:09:25
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class singleton
{
	class autorelease
	{
		public:
			autorelease ()
			{
				cout<< "autorelease()"<<endl;
			}

			~autorelease()
			{
				cout<< "~autorelease()"<<endl;
			if(_pinstance)
			{
				delete _pinstance;
			}
			}
	};

	public:
	static  singleton * getinstance()
	{
		if(_pinstance==NULL)
		{
			_pinstance = new singleton;
				return _pinstance;
		}
	}
		static void destroy()
		{
			if(_pinstance)
				delete _pinstance;
		}

		private :
		singleton ()
		{
			cout<< "singleton()"<<endl;
		}
		~singleton()
		{
			cout<<"~singleton()"<<endl;
		}

		private :
		
		 autorelease _ar;


		static singleton * _pinstance;
	};

//	singleton:: autorelease singleton::_ar;
	singleton * singleton ::_pinstance =NULL;

	int main(void)
	{
		singleton * p1=singleton ::getinstance();
		singleton * p2=singleton ::getinstance();
cout<<"p1="<<p1<<endl;
cout<<"p2="<<p2<<endl;

return 0;
	}

