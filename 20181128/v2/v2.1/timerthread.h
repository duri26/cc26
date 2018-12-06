 ///
 /// @file    timerthread.h
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-12-06 16:02:11
 ///

#ifndef __WD_TIMERTHREAD_H__
#define __WD_TIMERTHREAD_H__

#include "thread.h"
#include "timer.h"

namespace wd
{

class TimerThread
{
	public:
		using TimerCallBack = Timer::TimerCallBack;
		TimerThread(TimerCallBack && cb,int intitalTime,int intervalTime);
		void stop();
		void start();

	private:
		Timer _timer;
		Thread _thread;
};

}

#endif
