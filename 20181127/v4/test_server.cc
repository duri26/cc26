 ///
 /// @file    test_server.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-12-03 11:30:12
 ///

#include "tcpserver.h"
#include "threadpool.h"

#include <iostream>

using std::cout;
using std::endl;

class Task
{

public:
	Task(const string & query,const wd::TcpConnectionPtr & conn)
	:_queury(query)
	 ,_conn(conn)
	{}

	void process()
	{
		cout<<">>> task is process "<< endl;

		_conn->sendInLoop(_queury);
	}

private:
	string _queury;
	wd::TcpConnectionPtr _conn;
};

wd::Threadpool * g_threadpool = NULL;

void onConnection(const wd::TcpConnectionPtr && conn)
{
	cout<<conn->toString() <<endl;
	conn->send("hello, welcome to server.\r\n");
}

//运行IO线程
void onMessage(const wd::TcpConnectionPtr & conn)
{
	std::string s(conn->receive());
	
	//conn->send(s);//数据回显
	

#if 1
	Task task(s,conn);
	//在IO线程中，将任务的执行交给线程池处理
	g_threadpool->addTask(std::bind(&Task::process,task));
	cout<<" >>> add task to threadpool "<<endl;

#endif
}

void onClose(const wd::TcpConnectionPtr & conn)
{
	printf("%s close \n",conn->toString().c_str());
}

//组合设计模式
#if 0
class SearchEngineServer
{
public:
	onConnection(const wd::TcpConnectionPtr & conn);
	onMessage(const wd::TcpConnectionPtr & conn);
	onClose(const wd::TcpConnectionPtr & conn);
private:
	Threadpool _threadpool;//进行计算
	TcpServer _server;//网络通信
	TextQuery _tq;//业务逻辑
}
#endif

int main(int argc,char const **argv)
{
	wd::Threadpool threadpool(4,10);
	g_threadpool = &threadpool;
	threadpool.start();

	wd::TcpServer tcpserver("0.0.0.0",6666);
	tcpserver.setConnectionCallback(&onConnection);
	tcpserver.setMessageCallback(&onMessage);
	tcpserver.setCloseCallback(&onClose);

	tcpserver.start();

	return 0;
}

