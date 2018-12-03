 ///
 /// @file    condition.h
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-12-03 10:11:21
 ///

#ifndef __WD_CONDITION_H__
#define __WD_CONDITION_H__

#include "noncopyable.h"
#include "mutexlock.h"

#include <pthread.h>

namespace wd
{
	
class Condition
: Noncopyable
{
public:
	Condition(MutexLock & mutex)
	: _mutex(mutex)
	{	pthread_cond_init(&_cond, NULL);	}

	~Condition()
	{	pthread_cond_destroy(&_cond);	}

	void wait() 
	{	pthread_cond_wait(&_cond, _mutex.getMutexLockPtr());	}

	void notify()
	{	pthread_cond_signal(&_cond);	}

	void notifyAll()
	{	pthread_cond_broadcast(&_cond);	}

private:
	pthread_cond_t _cond;
	MutexLock & _mutex;
};


}

#endif

