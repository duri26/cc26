 ///
 /// @file    tcpconnection.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-30 22:11:21
 ///

#include "tcpconnection.h"
#include "epollpoller.h"

#include <string.h>
#include <stdio.h>

namespace wd
{

TcpConnection::TcpConnection(int sockfd,EpollPoller * loop)
	:_sockfd(sockfd)
	 ,_sockIO(sockfd)
	 ,_localAddr(wd::Socket::getLocalAddr(sockfd))

