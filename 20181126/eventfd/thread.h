 ///
 /// @file    thread.h
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-30 17:49:05
 ///

#ifndef __WD_THREAD_H__
#define __WD_THREAD_H__

#include "noncopyable.h"

#include <pthread.h>

#include <functional>

namespace wd
{

class Thread
	:Noncopyable
{
	public:
		using ThreadCallback = std::function<void ()>;
		Thread(ThreadCallback && cb)
		:_pthid(0)
		,_isRunning(false)
		,_cb(std::move(cb))
		{}

		~Thread();

		void start();
		void join();

		bool isRunning() const 
		{
		return _isRunning;
		}

		private:
		static void * threadFunc(void * arg);

		private:
		pthread_t _pthid;
		bool _isRunning;
		ThreadCallback _cb;
};

}

#endif
				
