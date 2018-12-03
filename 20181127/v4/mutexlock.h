 ///
 /// @file    mutexlock.h
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-12-01 11:12:30
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
		}

		void unlock()
		{
			pthread_mutex_unlock(&_mutex);
		}

		pthread_mutex_t * getMutexLockPtr()
		{
			return &_mutex;
		}

	private:
		pthread_mutex_t _mutex;
};


//RAII
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

