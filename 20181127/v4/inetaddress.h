 ///
 /// @file    inetaddress.h
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-26 19:46:57
 ///

#ifndef __WD_INETADDRESS_H__
#define __WD_INETADDRESS_H__

#include <netinet/in.h>
#include <string>

using std::string;

namespace wd
{

class InetAddress
{
	public:
		InetAddress(short port);

		InetAddress(const char *pIp,short port);

		InetAddress(const struct sockaddr_in &addr);

		const struct sockaddr_in * getSockAddrPtr()const;
		string ip()const ;
		unsigned short port()const;

	private:
		struct sockaddr_in _addr;
};

}

#endif
