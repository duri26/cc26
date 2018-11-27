 ///
 /// @file    workerthread.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-22 17:21:44
 ///

#include "workerthread.h"
#include "threadpool.h"

using namespace wd;

WorkerThread::WorkerThread(Threadpool & tp)
	:_threadpool(tp)
{}

WorkerThread:: ~WorkerThread()
{
	cout<<"~WorkerThread()"<<endl;
}

void WorkerThread::run()
{
	_threadpool.threadFunc();
}

