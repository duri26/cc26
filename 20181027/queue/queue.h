 ///
 /// @file    queue.h
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-10-29 21:35:52
 ///
#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;

class queue
{
	public:
		queue();

		void push(int);
		void pop();
		int front();
		int back();
		bool empty();
		bool full();

	private:
		string::    size_type _head;
		string::	size_type _tail;
//		int _data[11];
//static const int _len=10;
		int _data[8];
static const int _len=7;
};

#endif
