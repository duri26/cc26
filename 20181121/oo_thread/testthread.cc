 ///
 /// @file    testthread.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-21 20:48:43
 ///

#include "thread.h"

#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#include <iostream>
#include <memory>
//#include <functional>

using namespace wd;
using namespace std;

class MyThread
:public Thread
{
	void run()
		{
			::srand(::clock());
			int cnt = 50;
			while(cnt --)
			{
				int number =::rand() % 100;
				cout<<">>> subThread "<<pthread_self()<<": number= "<<number<<endl;
				::sleep(1);
			}
		}
		~MyThread()
		{
			cout<<"~MyThread()"<<endl;
		}
};


int main(void)
{
	cout<<">>oo_thread  mainTread: "<<pthread_self()<<endl;
	unique_ptr<Thread> pthread (new MyThread());
	//	(new Thread(
	//			
	//				//	std::bind(&Foo::threadFunc,Foo())
	//			//	execute
	//				));
	pthread->start();
	pthread->join();

	return 0;
}
