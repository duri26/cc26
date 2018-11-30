 ///
 /// @file    timerthread.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-30 16:48:19
 ///

#include "timerthread.h"

using namespace wd;

TimerThread::TimerThread(TimerCallback && cb,int intitilTime
		,int intervalTime)
    	:_timer(std::move(cb),intitilTime,intervalTime)
		 ,_thread(std::bind(&Timer::start,&_timer))
{
}

void TimerThread::start()
{
	_thread.start();
}

void TimerThread::stop()
{
	_timer.stop();
	_thread.join();
}
				

