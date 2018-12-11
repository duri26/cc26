 ///
 /// @file    MutexLock.h
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-12-11 16:50:40
 ///
#ifndef __MYSP_MUTEX_H__
#define __MYSP_MUTEX_H__

#include "Noncopyable.h"

#include <pthread.h>

namespace mysp
{

class MutexLock
	:private Noncopyable
{
	public:
		MutexLock()
			:isLocked(false)
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
			isLocked = true;
		}

		void unlock()
		{
			pthread_mutex_unlock(&_mutex);
			isLocked = false;
		}

		pthread_mutex_t * getMutexPtr()
		{
			return & _mutex;
		}

	private:
		pthread_mutex_t _mutex;
		bool isLocked;
};

class AutoLock
{
	public:
		AutoLock(MutexLock & mutex)
			:_mutex(mutex)
		{
			_mutex.lock();
		}

		~AutoLock()
		{
			_mutex.unlock();
		}

	private:
		MutexLock & _mutex;
};

}

#endif
