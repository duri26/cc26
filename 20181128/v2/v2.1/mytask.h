 ///
 /// @file    mytask.h
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-12-04 15:21:35
 ///

#ifndef __WD_MYTASK_H__
#define __WD_MYTASK_H__

#include "myresult.h"
#include "tcpconnection.h"

#include <vector>
#include <queue>
#include <string>

using namespace std;

namespace wd
{

class MyTask
{
	public:
		MyTask(const string &,const TcpConnectionPtr &);
		void excute();

	private:
		int distance(const string &);
		void response();

		int getBytesCode(char);
		string getNthChar(const string &,int);
		int getLength(const string &);

		private:
		string _queryWord;
		TcpConnectionPtr _conn;
		priority_queue<MyResult,vector<MyResult>> _resultQue;
};

}

#endif
		
