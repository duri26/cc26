 ///
 /// @file    test_server.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-23 23:54:17
 ///

#include "socketutil.h"
#include "inetaddress.h"
#include "socketIO.h"
#include "acceptor.h"
#include "tcpconnection.h"

#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::endl;

using namespace wd;

int main(int argc,char const **argv)
{
	InetAddress addr("192.168.80.128",3333);
	Acceptor acceptor(createSocketFd(),addr);
	acceptor.ready();

int peerfd =acceptor.accept();
TcpConnection conn(peerfd);
conn.send("welcome to char server");

while(1)
{
	string msg = conn.receive();
	cout<<"server receve: "<<msg<<endl;
	conn.send(msg);
}
return 0;
}


