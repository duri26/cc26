 ///
 /// @file    eventfdthread.h
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-30 20:42:31
 ///

#ifndef __WD_EVENTFD_THREAD_H__
#define __WD_EVENTFD_THREAD_H__

#include "eventfd.h"
#include "thread.h"

namespace wd
{

class EventfdThread
{
	public:
		using EventfdCallback = std::function<void ()>;
		EventfdThread(EventfdCallback && cb);

		void start();
		void stop();
		void wakeup();

	private:
		Eventfd _eventfd;
		Thread _thread;
};

}

#endif
