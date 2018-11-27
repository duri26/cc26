 ///
 /// @file    acceptor.h
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-23 23:39:02
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
		int  accept();

		int fd() const {return listenSock_.fd();}

	private:
		void setReuseAddr(bool on);
		void setReusePort(bool on);
		void bind();
		void listen();

	private:
		Socket listenSock_;
		InetAddress addr_;
};

}

#endif
