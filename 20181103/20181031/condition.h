 ///
 /// @file    condition.h
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-15 17:28:04
 ///
 //

#ifndef __WD_CONDITION_H__
#define __WD_CONDITION_H__

#include <pthread.h>

namespace wd
{
	class MutexLock;

	
	class Condition
	{
		public:
			Condition(MutexLock & mutex);
			~Condition();
			Condition(const Condition &)  =delete;
			Condition & operator =(const Condition &)=delete;

			void wait();
			void notify();
			void notifyAll();

		private:
			pthread_cond_t _cond;
			MutexLock & _mutex;
	};

}

#endif
