 ///
 /// @file    eventfd.h
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-30 20:28:36
 ///

#ifndef __WD_EVENTFD_H__
#define __WD_EVENTFD_H__

#include <functional>

namespace wd
{

class Eventfd
{
	public:
		using EventfdCallback = std::function<void()>;

		Eventfd(EventfdCallback && cb);
		~Eventfd();

		void start();
		void stop();
		void wakeup();

	private:
		int createEventfd();
		void handleRead();

	private:
		EventfdCallback _cb;
		int _fd;
		bool _isStarted;
};

}

#endif
