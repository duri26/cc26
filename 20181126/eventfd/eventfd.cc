 ///
 /// @file    eventfd.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-30 20:35:05
 ///

#include "eventfd.h"

#include <unistd.h>
#include <errno.h>
#include <poll.h>
#include <sys/eventfd.h>

#include <iostream>

using std::cout;
using std::endl;

using namespace wd;

Eventfd::Eventfd(EventCallback && cb)
	:_cb(std::move(cb))
	 ,_fd(createEventfd())
	 ,_isStarted(false)
{
}

Eventfd::~Eventfd()
{
	if(_isStarted)
		stop();
}

void Eventfd::start()
{
	_isStarted = true;
	
	struct pollfd pfd;
	pfd.fd =fd;
	pfd.events = POLLIN;

	while(_isStarted)
	{
		int nready =::poll(&pfd,1,5000);
		if(nready == -1 && errno == EINTR)
			continue;
		else if(nready == -1) {
			perror("poll");
			exit(EXIT_FAILURE);
		} else if(nready == 0) 
			printf(">>> poll has timeout!!\n\n");
		else {
			if(pfd.revents & POLLIN) {
				handleRead();//处理读事件
				if(_cb) _cb();//执行任务
			}
		}
	}
}
	
void Eventfd::stop()
{
	if(_isStarted)	{
		_isStarted = false;
	}
}

void Eventfd::wakeup()
{
	uint64_t one = 1;
	int ret = ::write(_fd, &one, sizeof(one));
	if(ret != sizeof(one))
	{
		perror("write");
	}
}

int Eventfd::createEventfd()
{
	int fd = ::eventfd(0, 0);
	if(fd == -1) {
		perror("eventfd");
	}
	return fd;
}
 

void Eventfd::handleRead()
{
	uint64_t howmany;
	int ret = ::read(_fd, &howmany, sizeof(uint64_t));
	if(ret != sizeof(uint64_t)) {
		perror("read");
	}
}

