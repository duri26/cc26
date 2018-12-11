 ///
 /// @file    TcpServer.h
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-12-11 11:19:07
 ///

#ifndef __MYSP_TCPSERVER_H__
#define __MYSP_TCPSERVER_H__

#include "Acceptor.h"
#include "EpollPoller.h"

namespace mysp
{

class TcpServer
{

public:
	using port_t = unsigned short;
	using CallBack = EpollPoller::EpollPollerCallBack;

	TcpServer(const string &,port_t,int);
	TcpServer(port_t,int);
	void start();
	void stop();

	void setAllCallBack(CallBack,CallBack,CallBack);
private:
	Acceptor _acceptor;
	EpollPoller _epoller;
};

}

#endif

