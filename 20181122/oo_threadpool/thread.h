 ///
 /// @file    thread.h
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-22 15:36:56
 ///

#ifndef __WD_THREAD_H__
#define __WD_THREAD_H__

#include "noncopyable.h"
#include <pthread.h>

namespace wd
{

class Thread
	:Noncopyable
{
	public:
	 Thread()
	 :_pthid(0)
	  ,_isRunning(false)
	{
	}

	 virtual ~Thread();

	 void start();
	 void join();

	 bool isRunning() const
	 {
		 return _isRunning;
	 }

	private:
	 virtual void run()=0;

	 static void * threadFunc(void * arg);//因为静态函数没有this

	private:
	 pthread_t _pthid;
	 bool _isRunning;
};

}

#endif
