 ///
 /// @file    MyTask.h
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-12-11 21:40:20
 ///

#ifndef __MYSP_MYTASK_H__
#define __MYSP_MYTASK_H__

#include <vector>
#include <queue>
#include <string>

#include "MyResult.h"
#include "TcpConnection.h"

using namespace std;

namespace mysp
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
		priority_queue<MyResult,vector<MyResult>> _resultQue;//优先队列
};

}

#endif
