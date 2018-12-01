 ///
 /// @file    epollpoller.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-12-01 11:36:22
 ///

#include "epollpoller.h"
#include "socketutil.h"
#include "acceptor.h"

#include <assert.h>
#include <iostream>

using std::cout;
using std::endl;

namespace wd
{

EpollPoller::EpollPoller(Acceptor & acceptor)
	:_acceptor(acceptor)
	 ,_epollfd(createEpollFd())
	 ,_eventfd(createEventFd())
	 ,_listenfd(_acceptor.fd())
	 ,_isLooping(false)
	 ,_eventsList(1024)
	{
		addEpollFdRead(_epollfd,_listenfd);
		addEpollFdRead(_epollfd,_eventfd);
	}

EpollPoller::~EpollPoller()
{
	::close(_epollfd);
}

void EpollPoller::loop()
{ 
	_isLooping = true;
	while(_isLooping)
	{
		waitEpollfd();
	}
}

void EpollPoller::unloop()
{
	if(_isLooping)
		_isLooping = false;
}

void EpollPoller::setConnectionCallback(EpollCallback cb)
{
	_onConnectionCb =cb;
}

