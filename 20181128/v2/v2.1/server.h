 ///
 /// @file    server.h
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-12-04 10:49:04
 ///

#ifndef __WD_SERVER_H__
#define __WD_SERVER_H__

#include "tcpserver.h"
#include "threadpool.h"

namespace wd
{
class Server
{
  public:
	using ServerCallBack = TcpServer::TcpServerCallback;
	using port_t = unsigned short; 

	Server(const string &,port_t,int,int);

	virtual ~Server();

	virtual void start() = 0;
	void stop();

  protected:
	virtual void onConnection(const TcpConnectionPtr &) =0;
	virtual void onMessage(const TcpConnectionPtr &) = 0;
	virtual void onClose(const TcpConnectionPtr &) = 0;

	protected:
	TcpServer _tcpServer;
	Threadpool _pthreadPool;
};

}

#endif
