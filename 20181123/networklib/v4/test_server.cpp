
#include "TcpServer.h"
#include "Threadpool.h"
#include <iostream>
using std::cout;
using std::endl;


class Task
{
public:
	Task(const string & query, const wd::TcpConnectionPtr & conn)
	: _queury(query)
	, _conn(conn)
	{}
	
	//运行在计算线程
	void process()
	{
		cout << "> task is processing" << endl;
		//...  process query

		//_conn->send(_queury);//进行数据的发送操作在计算线程之中, 此时与设计不符
							 //send方法的调用要延后,将其包装成一个函数对象注册给EpollPoller
							 //对象, 然后再在其事件循环过程中执行
		_conn->sendInLoop(_queury);
	}
private:
	string _queury;
	wd::TcpConnectionPtr _conn;
};

wd::Threadpool * g_threadpool = NULL;

void onConnection(const wd::TcpConnectionPtr &conn)
{
	cout << conn->toString() << endl;
    conn->send("hello, welcome to Chat Server.\r\n");
}

//运行在IO线程
void onMessage(const wd::TcpConnectionPtr &conn)
{
    std::string s(conn->receive());

	//conn->send(s);//数据回显

#if 1
	Task task(s, conn);
	//在IO线程中，将任务的执行交给线程池处理
	g_threadpool->addTask(std::bind(&Task::process, task));
	cout << "> add task to threadpool" << endl;
#endif
}

void onClose(const wd::TcpConnectionPtr &conn)
{
    printf("%s close\n", conn->toString().c_str());
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

int main(int argc, char const *argv[])
{
	wd::Threadpool threadpool(4, 10);
	g_threadpool = &threadpool;
	threadpool.start();

	wd::TcpServer tcpserver("0.0.0.0", 6666);
	tcpserver.setConnectionCallback(&onConnection);
	tcpserver.setMessageCallback(&onMessage);
	tcpserver.setCloseCallback(&onClose);

	tcpserver.start();

    return 0;
}
