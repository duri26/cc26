 ///
 /// @file    eventfdthread.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-30 20:51:35
 ///
#include "eventfdthread.h"

#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <pthread.h>

#include <functional>
#include <iostream>
using std::cout;
using std::endl;
using namespace wd;

struct Foo
{
	void getNumber()
	{
		::srand(::time(NULL));
		int number =::rand() % 100;
		cout<<" >> eventfd subThread "<<pthread_self()
			<<" : getNumber = "<<number<<endl;
	}

};

int main(void)
{
	EventfdThread eventfd(std::bind(&Foo::getNumber,Foo()));
	eventfd.start();
	int cnt =10;
	while(cnt--)
	{
		eventfd.wakeup();

		sleep(3);
	}
	eventfd.stop();
	return 0;
}
