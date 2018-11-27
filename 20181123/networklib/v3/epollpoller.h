 ///
 /// @file    epollpoller.h
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-26 23:25:18
 ///

#ifndef __WD_EPOLLPOLLER_H__
#define __WD_EPOLLPOLLER_H__

#include "noncopyable.h"
#include "tcpconnection.h"

#include <sys/epoll.h>
#include <vector>
#include <map>
#include <functional>

namespace wd
{

class Acceptor;

class EpollPoller
	:Noncopyable
{
	public:
		using EpollCallback = TcpConnection::TcpConnectionCallback;
		using Functor= std::function<void()>;

		EpollPoller(Acceptor & acceptor);
		~EpollPoller();

		void loop();
		void unloop();
		void doPendingFunctors();

		void setConnectionCallback(EpollCallback cb);
		void setMessageCallback(EpollCallback cb);
		void setCloseCallback(EpollCallback cb);

	private:
		void waitEpollfd();
		void handleConnection();
		void handleMessage(int peerfd);

	private:
		Acceptor & _acceptor;
		int _epollfd;
		int _listenfd;
		bool _isLooping;

		using EventList = std::vector<struct epoll_event> ;
		EventList _eventsList;

		using ConnectionMap = std::map<int,TcpConnectionPtr>;
		ConnectionMap _connMap;

		EpollCallback _onConnectionCb;
		EpollCallback _onMessageCb;
		EpollCallback _onCloseCb;
};

}

#endif
