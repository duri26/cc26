 ///
 /// @file    threadpool.h
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-22 15:30:36
 ///

#ifndef __WD_THREADPOOL_H__
#define __WD_THREADPOOL_H__

#include "taskqueue.h"
#include "task.h"

#include <iostream>
#include <vector>
#include <memory>

using namespace std;

namespace wd
{

class Thread;
class WorkerThread;

class Threadpool
{
	friend WorkerThread;

	public:
	Threadpool(size_t threadNum,size_t queSize);
	~Threadpool();

	void start();
	void stop();
	void addTask(Task * ptask);

	private:
	Task * getTask();
	void threadFunc();

	private:
	size_t _threadNum;
	size_t _queSize;
	vector<unique_ptr<Thread>> _threads;
	TaskQueue _que;
	bool _isExit;
};

}

#endif
