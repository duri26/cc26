///
/// @file    socketutil.h
/// @author  duri(1197010670@qq.com)
/// @date    2018-11-26 20:26:52
///


#ifndef __WD_SOCKETUTIL_H__
#define __WD_SOCKETUTIL_H__

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/eventfd.h>
#include <sys/epoll.h>

namespace wd
{

	inline int createSocketFd()
	{
		int fd=::socket(AF_INET,SOCK_STREAM,0);
		if(-1 ==fd)
		{
			perror("socket create");
		}
		return fd;
	}

	inline void setNonblock(int fd)
	{
		int flags=::fcntl(fd,F_GETFL,0);
		flags  |= O_NONBLOCK;
		::fcntl(fd,F_SETFL,flags);
	}

	inline int createEpollFd()
	{
		int efd=::epoll_create1(0);//注意 epoll_create1
		if(-1==efd)
		{
			perror("epoll_create");
			exit(-1);
		}
		return efd;
	}

	inline int createEventFd()
	{
		int evtfd=::eventfd(0,EFD_NONBLOCK|EFD_CLOEXEC);
		if(-1 == evtfd)
		{
			perror("eventfd");
		}
		return evtfd;
	}

	inline void addEpollFdRead(int efd,int fd)
	{
		struct epoll_event ev;
		ev.data.fd=fd;
		ev.events =EPOLLIN;
		int ret = epoll_ctl(efd,EPOLL_CTL_ADD,fd,&ev);
		if(-1==ret)
		{
			perror("epoll_ctl add");
			exit(-1);
		}
	}

	inline void delEpollReadFd(int efd,int fd)
	{
		struct epoll_event ev;
		ev.data.fd = fd;
		int ret = epoll_ctl(efd, EPOLL_CTL_DEL, fd, &ev);
		if(-1 == ret)
		{
			perror("epoll_ctl del error");
			exit(EXIT_FAILURE);
		}
	}


	inline size_t recvPeek(int sockfd,void *buf,size_t len)
		{
			int nread;
			do
			{
				nread =::recv(sockfd,buf,len,MSG_PEEK);
			}while(-1 ==nread && errno ==EINTR);

			return nread;
		}

	inline bool isConnectionClosed(int sockfd)
	{
		char buf[1024];
		int nread =recvPeek(sockfd,buf,sizeof(buf));
		if(-1 == nread)
		{
			perror("recvPeek-----");
			return true;
		}
		return (0 == nread);
	}

}

#endif
