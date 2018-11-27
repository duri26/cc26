 ///
 /// @file    producer.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-22 09:04:38
 ///

#include "producer.h"
#include "taskqueue.h"

#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include <iostream>
using std::cout;
using std::endl;

using namespace wd;

Producer::Producer(TaskQueue & que)
: _que(que)
{}

void Producer::run()
{
	int cnt = 100;
	::srand(::clock());
	while(cnt--) {
		int number = ::rand() % 100;
		_que.push(number);
		cout << " >> producer thread: " <<  pthread_self()
			 << "  produce a number = " << number << endl;

		::sleep(1);
	}
}
 

