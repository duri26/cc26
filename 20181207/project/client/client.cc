 ///
 /// @file    client.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-12-07 16:09:12
 ///

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <json/json.h>

#include <iostream>

using namespace std;

#define ERR_EXIT(m)   \
{ perror(m);      \
	exit(EXIT_FAILURE);}

void do_service(int );

int main(int argc,const char ** argv)
{
	int peerfd = socket(PF_INET,SOCK_STREAM,0);
	if(peerfd == -1)
	ERR_EXIT("socket");
struct sockaddr_in addr;
memset(&addr,0,sizeof(addr));
addr.sin_family = AF_INET;
addr.sin_addr.s_addr = inet_addr("192.168.80.128");
addr.sin_port = htons(9999);

socklen_t len = sizeof(addr);
if(connect(peerfd,(struct sockaddr*)&addr,len) == -1)
	ERR_EXIT("connect");

char buf[1024];
memset(buf,0,sizeof(buf));
int num;
read(peerfd,&num,4);
read(peerfd,buf,num);
printf("%s\n",buf);

do_service(peerfd);

return(peerfd);

return 0;
}

void do_service(int sockfd)
{
	char recvbuf[1024] ={0};
	char sendbuf[1024] ={0};
	int num;
	while(1)
	{
		fgets(sendbuf,sizeof(sendbuf),stdin);
		write(sockfd,sendbuf,strlen(sendbuf));//send没区别,一次只读一行

		//read
		int nnum = read(sockfd,&num,4);
		if(nnum == -1)
		{
			if(errno == EINTR) //中断，重试
				continue;
			ERR_EXIT("read");
		}
		else if(nnum == 0)
		{
			printf("server close !\n");
			close(sockfd);
			exit(EXIT_SUCCESS);
		}

		int nread = read(sockfd,recvbuf,num);
		if(nread == -1)
		{
			if(errno == EINTR)
			continue;
			ERR_EXIT("read");
		}
		else if(nread == 0)
		{
			printf("server close !\n");
			close(sockfd);
			exit(EXIT_SUCCESS);
		}

		Json::Reader reader;
		Json::Value value;
		Json::Value ::Members mem;
		if(!reader.parse(recvbuf,value))
		{
			return ;
		}
		for(const auto & val: value)
		{
			cout<<val.asString()<<endl;
		}

		cout<<"\n"<<endl;

		memset(recvbuf,0,sizeof(recvbuf));
		memset(sendbuf,0,sizeof(sendbuf));
	}
}

