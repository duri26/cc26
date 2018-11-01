 ///
 /// @file    condition.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-10-31 21:11:25
 ///
#include "mutexlock.h"
#include "condition.h"

#include <iostream>
using std::cout;
using std::endl;

using namespace wd;

condition::condition(mutexlock &mutex)
	: _mutex(mutex)
{
	pthread_cond_init(& _cond,NULL);
}

condition::~condition()
{
	pthread_cond_destroy(& _cond);
}

void condition:: wait()
{
	pthread_cond_wait(& _cond, _mutex.getmutexlockptr());
}

void condition::notify()
{
	pthread_cond_signal(& _cond);
}

void condition:: notifyall()
{
	pthread_cond_broadcast(& _cond);
}


