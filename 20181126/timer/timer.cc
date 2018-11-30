 ///
 /// @file    timer.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-27 23:38:02
 ///

#include "timer.h"

#include <unistd.h>
#include <errno.h>
#include <poll.h>
#include <sys/timerfd.h>

#include <iostream>
using std::cout;
using std::endl;

using namespace wd;

Timer::Timer(TimerCallback && cb,int initialTime,int intervalTime)
	:_cb(std::move(cb))
	 ,_fd(createTimerfd())
	 ,_initialTime(initialTime)
	 ,_intervalTime(intervalTime)
	 ,_isStarted(false)
{
}

Timer::~Timer()
{
	if(_isStarted)
		stop();
}

void Timer::start()
{
	_isStarted = true;

	setTimerfd(_initialTime,_intervalTime);
	struct pollfd pfd;
	pfd.fd =_fd;
	pfd.events =POLLIN;

	while(_isStarted)
	{
		int nready = ::poll(&pfd,1,5000);
		if(nready == -1 && errno == EINTR)
			continue;
		else if(nready == -1)
		{
			perror("poll");
			exit(EXIT_FAILURE);
		}
		else if(nready == 0)
		{
			printf(">>> timer has timeout !\n\n");
		}
		else 
		{
			if(pfd.revents & POLLIN)
			{
				handleRead();
				if(_cb)
					_cb();
			}
		}
	}
}

void Timer::stop()
{
	if(_isStarted)
	{
		_isStarted = false;
		setTimerfd(0,0);
	}
}

int Timer::createTimerfd()
{
	int fd =::timerfd_create(CLOCK_REALTIME,0);
	if(fd == -1)
	{
		perror("timer_create");
	}
	return fd;
}

void Timer::setTimerfd(int initialTime,int intervalTime)
{
	struct itimerspec value;
	value.it_value.tv_sec = initialTime;
	value.it_value.tv_nsec = 0;
	value.it_interval.tv_sec = intervalTime;
	value.it_interval.tv_nsec= 0;

	int ret = ::timerfd_settime(_fd,0,&value,NULL);
	if(ret == -1)
	perror("timerfd_settime");
}

void Timer::handleRead()
{
	uint64_t howmany;
	int ret =::read(_fd,&howmany,sizeof(uint64_t));
	if(ret != sizeof(uint64_t))
	{
		perror("read");
	}
}

