 ///
 /// @file    testpc.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-22 09:12:52
 ///

#include "taskqueue.h"
#include "producer.h"
#include "consumer.h"

#include <iostream>
#include <memory>

using namespace wd;
using namespace std;

int main(void)
{
	TaskQueue taskque(10);
	unique_ptr<Thread> pProducer(new Producer(taskque));
	unique_ptr<Thread> pConsumer(new Consumer(taskque));

	pProducer->start();
	pConsumer->start();

	pProducer->join();
	pConsumer->join();

	return 0;
}
