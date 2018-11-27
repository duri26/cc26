 ///
 /// @file    workerthread.h
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-22 15:25:05
 ///

#ifndef __Wd_WORKERTHREAD_H__
#define __WD_WORKERTHREAD_H__

#include "thread.h"

namespace wd
{
	 
class Threadpool;

class WorkerThread
	:public Thread
{
	public:
		WorkerThread(Threadpool & tp);

		~WorkerThread();

	private:
		void run() override;

	private:
		Threadpool & _threadpool;
};

}

#endif
