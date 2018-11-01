 ///
 /// @file    mutexlock.h
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-10-31 20:35:07
 ///

#ifndef __WD_MUTEXLOCK_H__
#define __WD_MUTEXLOCK_H__

#include <pthread.h>

namespace wd
{
	class mutexlock
	{
		public:
			mutexlock();
			~mutexlock();

			mutexlock(const mutexlock &) =delete; //防止复制mutexlock; c++11
			mutexlock & operator =(const mutexlock &)=delete;

			void lock();
			void unlock();
			pthread_mutex_t * getmutexlockptr()
			{
				return & _mutex;
			}

		private :
			pthread_mutex_t _mutex;
	};

	class mutexlockguard
	{
		public:
			mutexlockguard(mutexlock & mutex)
				: _mutex(mutex)
			{
				_mutex.lock();
			}

			~mutexlockguard()
			{
				_mutex.unlock();//自动解锁，防止忘记
			}
		private:
			mutexlock & _mutex;
	};

}

#endif
