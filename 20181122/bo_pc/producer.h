 ///
 /// @file    producer.h
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-21 23:35:23
 ///

#ifndef __WD_PRODUCER_H__
#define __WD_PRODUCER_H__

#include "thread.h"

namespace wd
{

class TaskQueue;

class Producer
	:public Thread
{
	public:
		Producer(TaskQueue &);

	private:
		void run() override;

	private:
		TaskQueue & _que;
};

}

#endif

