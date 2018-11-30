 ///
 /// @file    timerthread.h
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-30 16:02:07
 ///

#ifndef __WD_TIMERTHREAD_H__
#define __WD_TIMERTHREAD_H__

#include "timer.h"
#include "thread.h"

namespace wd
{

class TimerThread
{

	public:

	using TimerCallback = std::function<void()>;
	TimerThread(TimerCallback && cb,int intitalTime
			,int intervalTime);

	void start();
	void stop();

	private:
	Timer _timer;
	Thread _thread;
};

}

#endif
