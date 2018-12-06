 ///
 /// @file    timerthread.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-12-06 16:06:54
 ///

#include "timerthread.h"

namespace wd
{

TimerThread::TimerThread(TimerCallBack && cb,int intitalTime,int intervalTime)
	:_timer(intitalTime,intervalTime,std::move(cb))
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

}
