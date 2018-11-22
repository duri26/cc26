///
/// @file    thread.h
/// @author  duri(1197010670@qq.com)
/// @date    2018-11-21 20:25:04
///

#ifndef __WD_THREAD_H__
#define __WD_THREAD_H__

#include "noncopyable.h"
#include <pthread.h>

//#include <functional>

namespace wd
{

	class Thread
		:Noncopyable
	{
		public:
			//		using ThreadCallback = std::function<void()>;
			Thread()
				:_pthid(0),_isRunning(false)
			{}

			virtual		~Thread();

			void start();
			void join();

			bool isRunning() const 
			{
				return _isRunning;
			}

		private: //虚函数的覆盖跟访问权限无
			virtual void run() =0;
			static void * threadFunc(void * arg);

		private:
			pthread_t _pthid;
			bool _isRunning;
	};

}

#endif
