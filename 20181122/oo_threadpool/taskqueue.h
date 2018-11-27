 ///
 /// @file    taskqueue.h
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-22 15:42:09
 ///

#ifndef __WD_TASKQUEUE_H__
#define __WD_TASKQUEUE_H__

#include "mutexlock.h"
#include "condition.h"

#include <queue>
using std::queue;

namespace wd
{

class Task;

using ElementType = Task *;

class TaskQueue
{
	public:
		TaskQueue(size_t);

		bool full() const;
		bool empty() const;

		void push(ElementType value);
		ElementType pop();

	private:
		size_t _size;
		queue<ElementType> _que;
		MutexLock _mutex;
		Condition _notFull;
		Condition _notEmpty;
};

}

#endif
