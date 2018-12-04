 //
 /// @file    tcpserver.h
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-26 23:09:20
 ///

#ifndef __WD_TCPSERVER_C__
#define __WD_TCPSERVER_C__

#include "acceptor.h"
#include "epollpoller.h"
#include <string>

using std::string;

namespace wd
{

class TcpServer
{
	public:
		using TcpServerCallback =EpollPoller::EpollCallback;
		TcpServer(const string & ip,unsigned short port);
		TcpServer(unsigned short port);

		void start();
		void stop();

		void setConnectionCallback(TcpServerCallback cb);
		void setMessageCallback(TcpServerCallback cb);
		void setCloseCallback(TcpServerCallback cb);

	private:
		Acceptor _acceptor;
		EpollPoller _poller;

		TcpServerCallback _connectionCallback;
		TcpServerCallback _messageCallback;
		TcpServerCallback _closeCallback;
		
};

}

#endif
