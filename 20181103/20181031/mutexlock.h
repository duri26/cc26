 ///
 /// @file    mutexlock.h
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-15 17:06:06
 ///
#ifndef __MUTEXLOCK_H__
#define __MUTEXLOCK_H__
#include <pthread.h>

namespace wd
{
	class MutexLock
	{
		public:
			MutexLock();
			~MutexLock();

			MutexLock(const MutexLock &) =delete;
			MutexLock & operator =(const MutexLock & )=delete;

			void lock();
			void unlock();
			pthread_mutex_t * getMutexLockPtr()
			{
				return & _mutex;
			}

		private:
			pthread_mutex_t _mutex;
	};

	class  MutexLockGuard
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
