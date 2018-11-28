#include "tcpserver.h" 
#include <iostream>

using std::cout;
using std::endl;

using namespace wd;


void onConnection(const TcpConnectionPtr &conn)
{
	cout << conn->toString() <<  " has connected!" << endl;
    conn->send("hello, welcome to Chat Server.\r\n");
}

void onMessage(const TcpConnectionPtr &conn)
{
    string s(conn->receive());
	cout << ">> server receive: " << s << endl;
	//decode 
	//compute
	//encode

	//Task task(s);
	//threadpool.addTask(task);
	
    conn->send(s);
}

void onClose(const TcpConnectionPtr &conn)
{
    printf("%s close\n", conn->toString().c_str());
}

int main(int argc, char const **argv)
{
	//wd::TcpServer tcpserver("192.168.80.128", 9999);
	TcpServer tcpserver("0.0.0.0", 9999);
//	wd::TcpServer tcpserver("127.0.0.1", 9999);
	tcpserver.setConnectionCallback(&onConnection);
	tcpserver.setMessageCallback(&onMessage);
	tcpserver.setCloseCallback(&onClose);

	tcpserver.start();

    return 0;
}
