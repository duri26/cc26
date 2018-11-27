 ///
 /// @file    consumer.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-21 23:41:29
 ///

#include "consumer.h"
#include "taskqueue.h"

#include <unistd.h>

#include <iostream>
using std::cout;
using std::endl;

using namespace wd;

Consumer ::Consumer(TaskQueue & que)
	:_que(que)
{}


void Consumer::run()
{
	int cnt =50;
	while(cnt --)
	{
		int number = _que.pop();
       cout<<" >>>cousumer thread : "<<pthread_self()
		   <<"consumer a number = "<<number<<endl;
	::sleep(2);
	}
}


