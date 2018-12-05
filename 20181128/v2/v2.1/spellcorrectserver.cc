 ///
 /// @file    spellcorrectserver.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-12-05 20:03:24
 ///
 
#include "Configuration.h"
#include "spellcorrectserver.h"
#include "mytask.h"

using namespace std::placeholders;
using namespace duri;
#include <iostream>

namespace wd
{
	SpellcorrectServer::SpellcorrectServer()
		:Server(getConfig("ip"),
				atoi(getConfig("port").c_str()),
//				atoi(getConfig("listenFdNum").c_str()),
				atoi(getConfig("phtreadNum").c_str()),
				atoi(getConfig("taskQueueSize").c_str()))
	{}

	void SpellcorrectServer::start()
	{
		_pthreadPool.start();
_tcpServer.setConnectionCallback(bind(&SpellcorrectServer::onConnection,this,_1));
_tcpServer.setMessageCallback(bind(&SpellcorrectServer::onMessage,this,_1));
_tcpServer.setCloseCallback(bind(&SpellcorrectServer::onClose,this,_1));

_tcpServer.start();
	}


void SpellcorrectServer::onConnection(const TcpConnectionPtr & conn)
{
	cout<<conn->toString() <<std::endl;
	conn->send("hello, welcome to SpellcorrectServer server .\r\n");
}

void SpellcorrectServer::onMessage(const TcpConnectionPtr & conn)
{
	std::string s(conn->receive());

	MyTask task(s, conn);

	_pthreadPool.addTask(std::bind(&MyTask::excute,task));
	cout<<">> add task to threadpool "<<endl;
}

void SpellcorrectServer::onClose(const TcpConnectionPtr & conn)
{
	cout<<conn->toString() <<"close"<<endl;
}

}

