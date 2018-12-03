 ///
 /// @file    acceptor.h
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-26 20:05:24
 ///

#ifndef __WD_ACCEPTOR_H__
#define __WD_ACCEPTOR_H__

#include "socket.h"
#include "inetaddress.h"

namespace wd
{

class Acceptor
{
	public:
		Acceptor(int listenfd,const InetAddress & addr);

		void ready();
		int accept();

		int fd() const {return _listenSock.fd();}

	private:
		void setReuseAddr(bool on);
		void setReusePort(bool on);
		void bind();
		void listen();

	private:
		Socket _listenSock;
		InetAddress _addr;
};

}

#endif
