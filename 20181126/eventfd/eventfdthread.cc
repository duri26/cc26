 ///
 /// @file    eventfdthread.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-30 20:58:34
 ///

#include "eventfdthread.h"

using namespace wd;

EventfdThread::EventfdThread(EventfdCallback && cb)
	:_eventfd(std::move(cb))
	 ,_thread(std::bind(&Eventfd::start,&_eventfd))
{
}

void EventfdThread::start()
{
	_thread.start();
}

void EventfdThread::stop()
{
	_eventfd.stop();
	_thread.join();
}

void EventfdThread::wakeup()
{
	_eventfd.wakeup();
}
