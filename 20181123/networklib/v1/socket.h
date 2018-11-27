 ///
 /// @file    socket.h
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-23 23:50:01
 ///

#ifndef __WD_SOCKET_H__
#define __WD_SOCKET_H__

#include "noncopyable.h"

namespace wd
{

class InetAddress;

class Socket
	:Noncopyable
{
	public:
		Socket(int sockfd);
		Socket();
		~Socket();

		void shutdownWrite();
		int fd()const { return sockfd_;}

		void nonblock();

		static InetAddress getLocalAddr(int sockfd);
		static InetAddress getPeerAddr(int sockfd);

	private:
		int sockfd_;
};

}

#endif
