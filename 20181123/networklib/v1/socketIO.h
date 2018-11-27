///
/// @file    socketIO.cc
/// @author  duri(1197010670@qq.com)
/// @date    2018-11-25 16:45:37
///

#include "socketIO.h"
#include "socketutil.h"


namespace wd
{

	SocketIO::SocketIO(int sockfd)
		:sockfd_(sockfd)
	{}

	size_t SocketIO::readn(char *buf,size_t count)
	{
		size_t nleft =count;
		char * pbuf =buf;
		while(nleft>0)
		{
			int nread =::read(sockfd_,pbuf,nleft);
			if(-1==nread)
			{
				if(errno == EINTR)
					continue;
				return EXIT_FAILURE;
			}
			else if(0==nread)
			{
				break;
			}
			pbuf += nread;
			nleft -= nread;
		}
		return (count -nleft);
	}

	size_t SocketIO::writen(const char *buf,size_t count)
	{
		size_t nleft =count;
		const char *pbuf =buf;
		while(nleft > 0)
		{
			int nwrite=::write(sockfd_,pbuf,nleft);
			if(nwrite == -1)
			{
				if(errno == EINTR)
					continue;
				return EXIT_FAILURE;
			}
			nleft -=nwrite;
			pbuf +=nwrite;
		}
		return (count -nleft);
	}

	size_t SocketIO::recv_peek(char *buf,size_t count)
	{
		int nread;
		do
		{
			nread =::recv(sockfd_,buf,count,MSG_PEEK);
		}while(nread == -1 &&errno == EINTR);
		return nread;
	}

	size_t SocketIO::readline(char *buf,size_t maxlen)
	{
		size_t nleft=maxlen -1;
		char *pbuf = buf;
		size_t total =0;
		while(nleft >0)
		{
			int nread =recv_peek(pbuf,nleft);
			if(nread<= 0)
				return nread;

			for(int idx=0;idx != nread;++idx)
			{
				if(pbuf[idx] =='\n')
				{
					size_t nsize =idx +1;
					if(readn(pbuf,nsize) != nsize)
						return EXIT_FAILURE;
					pbuf += nsize;
					total += nsize;
					*buf =0;
					return total;
				}
			}
			if(readn(pbuf,nread) != nread)
				return EXIT_FAILURE;
			pbuf += nread;
			nleft += nread;
			total += nread;
		}

		*pbuf =0;
		return maxlen -1;
	}

}


