 ///
 /// @file    thread.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-30 20:20:47
 ///

#include "thread.h"

using namespace wd;

void Thread::start()
{
	pthread_create(&_pthid,NULL,threadFunc,this);
	_isRunning = true;
}

void Thread::join()
{
	if(_isRunning)
	{
		pthread_join(_pthid,NULL);
		_isRunning = false;
		}
}

Thread::~Thread()
{
	if(_isRunning)
	{
		pthread_detach(_pthid);
	_isRunning = false;
	}
}

void * Thread::threadFunc(void * arg)
{
	Thread * pthread = static_cast<Thread*>(arg);
	if(pthread)
		pthread->_cb();

	return NULL;
}
