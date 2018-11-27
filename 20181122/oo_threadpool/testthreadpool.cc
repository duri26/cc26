 ///
 /// @file    testthreadpool.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-22 17:26:10
 ///

#include "threadpool.h"

#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#include <iostream>

using namespace std;
using namespace wd;

class MyTask
:public Task
{
	public:
		void process()
		{
			::srand(::time(NULL));
			int number = ::rand() %100;
			cout<<"oo: subthread "<<pthread_self()
				<<" : get random number = "<<number<<endl;
			::sleep(1);
		}
};

int main(void)
{
	Threadpool threadpool(3,10);
	threadpool.start();

	int cnt = 20;
	unique_ptr<Task> task(new MyTask());
	while(cnt --)
	{
		threadpool.addTask(task.get());
//		::sleep(1);
	}

	threadpool.stop();

	return 0;
}
