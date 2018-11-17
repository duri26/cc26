 ///
 /// @file    mutexlock.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-15 17:23:22
 ///
#include "mutexlock.h" 
#include <iostream>
using std::cout;
using std::endl;

namespace wd
{
	MutexLock::MutexLock()
	{
		pthread_mutex_init(&_mutex,NULL);
	}

	MutexLock::~MutexLock()
	{
		pthread_mutex_destroy(& _mutex);
	}

	void MutexLock::lock()
	{
		pthread_mutex_lock(&_mutex);
	}

	void MutexLock::unlock()
	{
		pthread_mutex_unlock(&_mutex);
	}

}

