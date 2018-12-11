 ///
 /// @file    Socket.h
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-12-11 11:36:43
 ///

#ifndef __MYSP_SOCKET_H__
#define __MYSP_SOCKET_H__

#include "Noncopyable.h"

namespace mysp
{

class Socket
	:Noncopyable
{
public:
	 Socket();
	 explicit Socket(int);//防止隐式转换
	 ~Socket();

	 int fd() const;
	 void shutdownWrite();
	 void nonblock();

private:
	 int _sockFd;
};

int createSockFd();
}

#endif
