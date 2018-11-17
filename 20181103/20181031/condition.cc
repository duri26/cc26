 ///
 /// @file    condition.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-15 20:05:47
 ///

#include "condition.h"  //第一个头文件一定要是相应的头文件, 不能是其他的
#include "mutexlock.h"  //如果在头文件中使用了类的前向声明，则需要在实现文件中加载头文件

#include <iostream>
using std::cout;
using std::endl;

using namespace wd;

Condition::Condition(MutexLock & mutex)
: _mutex(mutex)
{
	pthread_cond_init(&_cond, NULL);
}

Condition::~Condition()
{
	pthread_cond_destroy(&_cond);
}

void Condition::wait() 
{
	pthread_cond_wait(&_cond, _mutex.getMutexLockPtr());
}

void Condition::notify()
{
	pthread_cond_signal(&_cond);
}

void Condition::notifyAll()
{
	pthread_cond_broadcast(&_cond);
}
 

