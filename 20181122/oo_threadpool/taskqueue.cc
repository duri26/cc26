 ///
 /// @file    taskqueue.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-22 17:45:21
 ///

#include "taskqueue.h"

using namespace wd;

TaskQueue::TaskQueue(size_t size)
	:_size(size)
	 ,_mutex()
	 ,_notFull(_mutex)
	 ,_notEmpty(_mutex)
{
}

bool TaskQueue::full() const
{
	return _que.size() == _size;
}

bool TaskQueue::empty() const
{
	return _que.size() == 0;
}

void TaskQueue::push(ElementType value)
{

	{
		MutexLockGuard autolock(_mutex);

		while(full())
	{
		_notFull.wait();
	}

		_que.push(value);
	}
	_notEmpty.notify();
}

ElementType TaskQueue::pop()
{
ElementType value;
{
	MutexLockGuard autolock(_mutex);
	while(empty())
	{
		_notEmpty.wait();
	}

	value = _que.front();
	_que.pop();
}
_notFull.notify();

return value;
}
