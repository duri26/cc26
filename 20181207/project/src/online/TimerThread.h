 ///
 /// @file    TimerThread.h
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-12-11 10:39:48
 ///

#ifndef __MYSP_TIMERTHREAD_H__
#define __MYSP_TIMERTHREAD_H__

#include "Pthread.h"
#include "Timer.h"

namespace mysp
{

class TimerThread
{
	public:
		using TimerCallBack = Timer::TimerCallBack;
		TimerThread(TimerCallBack && cb,int initialTime,int intervalTime);
		void start();
		void stop();

	private:
		Timer _timer;
		Pthread _thread;

};

}

#endif
