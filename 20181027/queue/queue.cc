 ///
 /// @file    queue.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-10-29 23:50:03
 ///
#include "queue.h"

#include <iostream>
using std::cout;
using std::endl;

queue::queue()
	:_head(0)
	 ,_tail(0)
{
}

void queue::push(int i)
	{
		if(!full())
		{
			_data[_tail]=i;
			_tail=(_tail + 1)%(_len+1);
		}
	}

void queue::pop()
{
	if(!empty())
	{
		_head=(_head+1)%(_len+1);
	}
}

int queue::front() 
{
	return _data[_head];
}

int queue::back()
{
	return _data[(_tail-1)%(_len +1)];
}

bool queue::empty()
{
	return _head==_tail;
}

bool queue::full()
{
	return (_tail +1)%(_len+1)==_head;
}
