 ///
 /// @file    taskqueue.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-12-03 10:22:16
 ///

#include "taskqueue.h"

using namespace wd;
 
//服务器所在的线程
void TaskQueue::push(Task && task)
{
	MutexLockGuard autoLock(_mutex);

	while(full())	
	{
		_notFull.wait();
	}

	_que.push(std::move(task));
	_notEmpty.notify();
}

//客户端所在的线程
Task TaskQueue::pop()
{
	MutexLockGuard autoLock(_mutex);
	while(_flag && empty())
	{
		_notEmpty.wait();//在这里阻塞
	}

	if(_flag) {
		Task task = _que.front();
		_que.pop();
		_notFull.notify();
		return task;
	} else
		return NULL;
}

