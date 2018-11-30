 ///
 /// @file    timer.h
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-27 23:33:06
 ///

#ifndef __WD_TIMER_H__
#define __WD_TIMER_H__

#include <functional>

namespace wd
{

class Timer
{
	public:
		using TimerCallback =std::function<void()>;

		Timer(TimerCallback && cb,int initialTime,int intervalTime);
		~Timer();

		void start();
		void stop();

	private:
		int createTimerfd();
		void setTimerfd(int ,int);
		void handleRead();

	private:
		TimerCallback _cb;
		int _fd;
		int _initialTime;
		int _intervalTime;
		bool _isStarted;
};

}

#endif
