 ///
 /// @file    tcpconnection.h
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-23 22:11:36
 ///

#ifndef __WD_TCPCONNECTION_H__
#define __WD_TCPCONNECTION_H__

#include "noncopyable.h"
#include "inetaddress.h"
#include "socket.h"
#include "socketIO.h"

#include <string>
#include <memory>
#include <functional>

namespace wd
{

class TcpConnection;
using TcpConnectionPtr  = std::shared_ptr<TcpConnection>;

class TcpConnection
	:Noncopyable
	 ,public std::enable_shared_from_this<TcpConnection>//什么鬼
{
  public:
	  using TcpConnectionCallback =std::function<void(const TcpConnectionPtr&)>;
	  TcpConnection(int sockfd);
	  ~TcpConnection();

	  std::string receive();
	  void send(const std::string & msg);
	  void shutdown();

	  std::string toString();

	  void setConnectionCallback(TcpConnectionCallback cb);
	void setMessageCallback(TcpConnectionCallback cb);
	void setCloseCallback(TcpConnectionCallback cb);

	void handleConnectionCallback();
	void handleMessageCallback();
	void handleCloseCallback();

  private:
	Socket _sockfd;
	SocketIO _sockIO;
	const InetAddress _localAddr;
	const InetAddress _peerAddr;
	bool _isShutdownWrite;

	TcpConnectionCallback _onConnectionCb;
	TcpConnectionCallback _onMessageCb;
	TcpConnectionCallback _onCloseCb;

};

}

#endif
