 ///
 /// @file    taskqueue.h
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-12-03 10:00:59
 ///

#ifndef __WD_TASKQUEUE_H__
#define __WD_TASKQUEUE_H__

#include "mutexlock.h"
#include "condition.h"

#include <queue>
#include <funcional>

namespace wd
{

using Task = std::function<void()>;

class TaskQueue
{

public:
	TaskQueue(size_t queSize)
		:_queSize(queSize)
		 ,_mutex()
		 ,_notFull(_mutex)
		 ,_notEmpty(_mutex)
		 ,_flag(true)
	{}

	void push(Task && task);
	Task pop();

	bool empty() const
	{
		return _que.size() == 0;
	}

	bool full() const 
{
	return _que.size() == _queSize;
}

void wakeup()
{
	_flag = false;
	_notEmpty.notifyAll();
}

private:
size_t _queSize;
std::queue<Task> _que;
MutexLock _mutex;
Condition _notFull;
Condition _notEmpty;
bool _flag;
};

}

#endif

