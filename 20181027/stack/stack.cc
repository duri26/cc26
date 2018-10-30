 ///
 /// @file    stack.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-10-29 21:02:58
 ///
#include "stack.h"

#include <iostream>
using std::cout;
using std::endl;


void stack:: push(int i)
{
	if(!full())
	{
//		_data[++_size]=i;  //注意前加加 后加加
		_data[_size++]=i;
	}
}

void stack:: pop()
{
	if(!empty())
	{
		--_size;
	}
}

int stack:: top() 
{
	return _data[_size-1];
}

bool stack:: empty() 
{
	return !_size;
}

bool  stack:: full() 
{
	return 10==_size;
}

