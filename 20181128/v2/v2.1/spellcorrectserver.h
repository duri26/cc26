 ///
 /// @file    spellcorrectserver.h
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-12-04 10:47:04
 ///

#ifndef __WD_SPELLCORRECTSERVER_H__
#define __WD_SPELLCORRECTSERVER_H__

#include "server.h"

namespace wd
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
