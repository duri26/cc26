 ///
 /// @file    sing.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-05 10:56:14
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
				_pinstance=new singleton();
			}
			return _pinstance;
		}
			static void destory()
			{
				if(_pinstance)
				{
					delete _pinstance;
				}
			}
		
			
			private:
			singleton()
			{
				cout <<"singleton()"<<endl;
			}

			~singleton()
			{
				cout<<"~singleton()"<<endl;
			}

			private:
	
		static singleton * _pinstance;
		};

		singleton * singleton:: _pinstance=nullptr;

	
int main(void)
{

	singleton * p1=singleton::getinstance();
	singleton * p2=singleton::getinstance();
cout<<"p1="<<p1<<endl;
cout<<"p2="<<p2<<endl;


p1->destory();
return 0;
}
