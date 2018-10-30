 ///
 /// @file    stack.h
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-10-29 20:53:08
 ///
#ifndef __STACK_H__
#define __STACK_H__

#include <iostream>
using std::cout;
using std::endl;

class stack
{
	public:
		stack()
			:_size(0)
		{}
		void push(int);
		void pop();
		int top();
		bool empty();
		bool full();

	private:
		size_t _size;
		int _data[10];
};

#endif
