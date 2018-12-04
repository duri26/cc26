 ///
 /// @file    server.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-12-04 11:02:29
 ///
#include "server.h"

namespace wd
{

Server::Server(const string & ip,port_t port
		,int threadNum,int queSize)
	:_tcpServer(ip,port),_pthreadPool(threadNum,queSize)
{}

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
