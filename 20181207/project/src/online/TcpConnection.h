 ///
 /// @file    TcpConnection.h
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-12-11 11:35:05
 ///

#ifndef __MYSP_TCPCONNECTION_H__
#define __MYSP_TCPCONNECTION_H__

#include "InetAddr.h"
#include "SocketIO.h"
#include "Socket.h"

#include <functional>
#include <memory>

using namespace std;

namespace mysp
{

class TcpConnection;
using TcpConnectionPtr = shared_ptr<TcpConnection>;

class EpollPoller;

class TcpConnection
	:public enable_shared_from_this<TcpConnection>
{
	public:
		using TcpConnectionCallBack = function<void(const TcpConnectionPtr&)>;

		TcpConnection(int ,EpollPoller *);
		~TcpConnection();
		string receive();
		void send(const string &);
		void shutDown();

		void handleConnectionCallBack();
		void handleMessageCallBack();
		void handleCloseCallBack();

		void setAllCallBack(TcpConnectionCallBack
				,TcpConnectionCallBack
				,TcpConnectionCallBack);

		string toString();
		void sendInLoop(const string &);

	private:
		bool _isShutdownWrite;
		Socket _peerSock;
		SocketIO _socketIO;
		EpollPoller * _epoller;
		const InetAddr _localAddr;
		const InetAddr _peerAddr;

		TcpConnectionCallBack _onConnectionCb;
		TcpConnectionCallBack _onMessageCb;
		TcpConnectionCallBack _onCloseCb;
		
};

bool isConnectionClosed(int);
}

#endif
