 //
 /// @file    thread.h
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-12-03 10:45:52
 ///

#ifndef __WD_THREAD_H__
#define __WD_THREAD_H__

#include "noncopyable.h"

#include <pthread.h>
#include <functional>

using std::function;

namespace wd
{

class Thread
	:Noncopyable
{

	using ThreadCallback = function<void()>;

	public:
	Thread(ThreadCallback && cb);
	~Thread();

	void start();
	void join();

	bool isRunning() const 
	{
		return _isRunning;
	}

	private:
	static void * threadFunc(void *);//采用静态成员函数，去掉this的影响

	private:
	pthread_t _pthid;
	bool _isRunning;
	ThreadCallback _cb;
};

}

#endif
