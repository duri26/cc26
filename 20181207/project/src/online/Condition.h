 ///
 /// @file    Condition.h
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-12-11 18:04:08
 ///

#ifndef __MYSP_CONDITION_H__
#define __MYSP_CONDITION_H__

#include "Noncopyable.h"
#include "MutexLock.h"

#include <pthread.h>

namespace mysp
{

class Condition
	:private Noncopyable
{
	public:
		Condition(MutexLock & mutex)
			:_mutex(mutex)
		{
			pthread_cond_init(&_cond,NULL);
		}

		~Condition()
		{
			pthread_cond_destroy(&_cond);
		}

		void wait()
		{
			pthread_cond_signal(&_cond);
		}

		void notifyall()
		{
			pthread_cond_broadcast(&_cond);
		}

	private:
		pthread_cond_t _cond;
		MutexLock & _mutex;
};

}

#endif
