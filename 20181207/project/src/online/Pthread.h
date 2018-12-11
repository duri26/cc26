 ///
 /// @file    Pthread.h
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-12-11 10:49:24
 ///

#ifndef __MYSP_PTHREAD_H__
#define __MYSP_PTHREAD_H__

#include "Noncopyable.h"

#include <pthread.h>

#include <string>
#include <functional>

using std::string;

namespace mysp
{

extern __thread const char * pthreadName; //extern表示外部定义，__thread 线程的局部存储

class Pthread
	:private Noncopyable
{

public:
	using PthreadCallBack = std::function<void()>;

	Pthread(PthreadCallBack &&,const string & name = string());
		~Pthread();

	void start();
	void join();

	bool isRunning() const
	{
		return _isRunning;
	}

private:
	static void * pthreadFunc(void *);

private:
	pthread_t _pthid;
	string _name;
	bool _isRunning;
	PthreadCallBack _cb;
};

}

#endif




