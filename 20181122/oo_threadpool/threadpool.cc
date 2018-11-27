 ///
 /// @file    threadpool.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-22 17:33:13
 ///

#include "threadpool.h"
#include "workerthread.h"

#include <unistd.h>

#include <iostream>

using namespace wd;

Threadpool::Threadpool(size_t threadNum,size_t queSize)
	:_threadNum(threadNum)
	 ,_queSize(queSize)
	 ,_que(queSize)
	 ,_isExit(false)
{
	_threads.reserve(threadNum);
}

Threadpool::~Threadpool()
{
	if(!_isExit)
	{
		stop();
	}
}

void Threadpool::addTask(Task * ptask)
{
	_que.push(ptask);
}

void Threadpool::start()
{
	for(size_t idx=0;idx != _threadNum;++idx)
	{
		unique_ptr<Thread> up(new WorkerThread(*this));
		_threads.push_back(std::move(up));
	}

	for(auto & thread: _threads)
		thread->start();
}

void Threadpool::stop()
{
	if(!_isExit)
	{
	while(!_que.empty())
	{
		sleep(1);
	}

	_isExit = true;
	for(auto & thread: _threads)
		thread->join();
	}
}

Task * Threadpool::getTask()
{
	return _que.pop();
}

void Threadpool::threadFunc()
{
	while(!_isExit)
	{
		Task * ptask = getTask();
		if(ptask)
			ptask->process();
	}
}

