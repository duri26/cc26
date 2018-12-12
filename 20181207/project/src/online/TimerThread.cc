 ///
 /// @file    TimerThread.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-12-12 20:46:31
 ///

#include "TimerThread.h"

namespace mysp
{

TimerThread::TimerThread(TimerCallBack && cb
, int intitalTime, int intervalTime)
: _timer(intitalTime, intervalTime, std::move(cb))
, _thread(std::bind(&Timer::start, &_timer))
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
 
