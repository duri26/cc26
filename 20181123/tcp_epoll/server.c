 ///
 /// @file    server.c
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-23 20:46:19
 ///

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define MAXEVENTS 2048
int main(void)
{
	int listenfd =socket(AF_INET,SOCK_STREAM,0);
	if(-1 == listenfd)
	{
		perror("socket");
		exit(-1);
	}

	int on =1;//一个服务器程序关闭之后，立马可以重启；
	if(setsockopt(listenfd,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on)) <0)
	{
		perror("sersockopt");
		close(listenfd);
		exit(-1);
	}

	//实现系统级别的负载均衡，一个服务器程序可以在同一台物理主机的同一时刻启动多次；
	if(setsockopt(listenfd,SOL_SOCKET,SO_REUSEPORT,&on,sizeof(on))<0)
	{
		perror("setsockopt");
		close(listenfd);
		exit(-1);
	}

	struct sockaddr_in serverAddr;
	printf("sizeof(struct sockaddr_in)=%ld \n",sizeof(struct sockaddr_in));
	memset(&serverAddr,0,sizeof(struct sockaddr_in));
	serverAddr.sin_family=AF_INET;
	serverAddr.sin_port=htons(3333);
	serverAddr.sin_addr.s_addr=INADDR_ANY;

	int ret =bind(listenfd,(struct sockaddr*)&serverAddr,
			sizeof(struct sockaddr));

	if(-1 == ret)
	{
		perror("bind");
		close(listenfd);
		exit(-1);
	}

	ret =listen(listenfd,10); //第二个参数的作用是，处理半链接状态的客户端的最大数量;
	if(-1 ==ret)
	{
		perror("listen");
		close(listenfd);
		exit(-1);
	}
int efd = epoll_create1(0);
if(-1==efd)
{
	perror("epoll_create1 error");
	exit(-1);
}
struct epoll_event evt_listen;
evt_listen.data.fd = listenfd;
evt_listen.events=EPOLLIN;
int ret1 =epoll_ctl(efd,EPOLL_CTL_ADD,listenfd,&evt_listen);
if(-1 ==ret1)
{
	perror("epoll_ctl add error");
	exit(EXIT_FAILURE);
}


// struct epoll_event *events =calloc(MAXEVENTS,sizeof(struct epoll_event));
struct epoll_event *events = calloc(MAXEVENTS, sizeof(struct epoll_event));
	while(1)
	{
		int peerFd =accept(listenfd,NULL,NULL);

		char buf[1024]="welcome to server";
		ret =write(peerFd,buf,strlen(buf));

		memset(buf,0,sizeof(buf));
		printf("> pls client data: \n");
		ret = read(peerFd,buf,1024);
		printf("%s \n",buf);
	}
	close(listenfd);
	return 0;
}
