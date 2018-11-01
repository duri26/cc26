 ///
 /// @file    condition.h
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-10-31 20:44:54
 ///

#ifndef __WD_CONDITION_H__
#define __WD_CONDITION_H__

#include <pthread.h>

namespace wd
{
	class mutexlock;// 类的前置申明

	class condition
	{
		public:
			condition(mutexlock & mutex);
			~condition();
			
			void wait();
			void notify();
			void notifyall();

		private:
			condition (const condition &);
			condition &operator =(const condition &);

			pthread_cond_t _cond;
			mutexlock & _mutex;
	};

}

#endif 
