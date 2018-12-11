 ///
 /// @file    SocketIO.h
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-12-11 11:51:40
 ///

#ifndef __MYSP_SOCKETIO_H__
#define __MYSP_SOCKETIO_H__

#include "Noncopyable.h"

#include <sys/types.h>

namespace mysp
{

ssize_t recvPeek(int ,char *, size_t);

class SocketIO
{

	public:
		explicit SocketIO(int);

		ssize_t recvAll(char *,size_t);//signed size_t有符号
		ssize_t sendAll(const char *,size_t);
		ssize_t sendUint32(unsigned int);
		ssize_t recvLine(char *,size_t);

	private:
		int _fd;
};

}

#endif
