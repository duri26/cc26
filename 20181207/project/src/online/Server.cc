 ///
 /// @file    Server.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-12-12 16:35:48
 ///

#include "Server.h"

namespace mysp
{

Server::Server(const string & ip, port_t port, int listenFdNum,
		int threadNum, int taskNum)
: _tcpServer(ip, port, listenFdNum)
, _pthreadPool(threadNum, taskNum)
{
}

/*
Server::Server(port_t port, int listenFdNum,
		int threadNum, int taskNum)
: _tcpServer(port, listenFdNum)
, _pthreadPool(threadNum, taskNum){
}*/

Server::~Server()
{
	stop();
}

void Server::stop()
{
	_pthreadPool.stop();
	_tcpServer.stop();
}

}

