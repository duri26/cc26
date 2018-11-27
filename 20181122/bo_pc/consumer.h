 ///
 /// @file    consumer.h
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-21 22:14:50
 ///

#ifndef __WD_CONSUMER_H__
#define __WD_CONSUMER_H__

#include "thread.h"

namespace wd
{

class TaskQueue;

class Consumer
	:public Thread
{
	public:
		Consumer(TaskQueue & que);

	private:
		void run() override;
		
	private:
		TaskQueue & _que;
};

}

#endif
