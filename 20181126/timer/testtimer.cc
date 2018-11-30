 ///
 /// @file    testtimer.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-30 16:54:44
 ///

#include "timerthread.h"

#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <pthread.h>

#include <iostream>
#include <functional>

using std::cout;
using std::endl;
using namespace wd;

struct Foo
{
	void getNumber()
	{
		::srand(::time(NULL));
		int number=::rand() % 100;
		cout<<" >> timerThread "<<pthread_self()
			<<" : getNumber = "<<number <<endl;
	}

};

int main(void)
{
	TimerThread timer(std::bind(&Foo::getNumber,Foo()),3,6);
	timer.start();
	sleep(20);
	timer.stop();
	
	return 0;
}
