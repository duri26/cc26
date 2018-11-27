 ///
 /// @file    mutexlock.h
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-21 22:21:28
 ///

#ifndef __WD_MUTEXLOCK_H__
#define __WD_MUTEXLOCK_H__

#include "noncopyable.h"

#include <pthread.h>

namespace wd
{

class MutexLock
	:Noncopyable
{
	public:
		MutexLock()
			:_isLocking(false)
		{
			pthread_mutex_init(&_mutex,NULL);
		}

		~MutexLock()
		{
			pthread_mutex_destroy(&_mutex);
		}

		void lock()
		{
			pthread_mutex_lock(&_mutex);
			_isLocking =true;
		}

		void unlock()
		{
			pthread_mutex_unlock(&_mutex);
			_isLocking = false;
		}

		pthread_mutex_t * getMutexLockPtr()
		{
			return & _mutex;
		}

	private:
		pthread_mutex_t _mutex;
		bool _isLocking;
};

class MutexLockGuard
{
	public:
		MutexLockGuard(MutexLock & mutex)
			:_mutex(mutex)
		{
			_mutex.lock();
		}

		~MutexLockGuard()
		{
			_mutex.unlock();
		}

	private:
		MutexLock & _mutex;
};

}

#endif 
