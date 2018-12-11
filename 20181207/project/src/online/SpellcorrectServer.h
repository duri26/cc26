 ///
 /// @file    SpellcorrectServer.h
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-12-11 22:13:42
 ///

#ifndef __MYSP_SPELLCORRECTSERVER_H__
#define __MYSP_SPELLCORRECTSERVER_H__

#include "Server.h"

namespace mysp
{

class SpellcorrectServer
	:public Server
{
	public:
		SpellcorrectServer();
		void start();

	private:
		void onConnection(const TcpConnectionPtr &);
		void onMessage(const TcpConnectionPtr &);
		void onClose(const TcpConnectionPtr &);

};

}

#endif

