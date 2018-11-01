 ///
 /// @file    mutexlock.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-10-31 20:52:00
 ///
#include "mutexlock.h"

#include <iostream>
using std::cout;
using std::endl;

namespace wd
{
	mutexlock::mutexlock()
	{
		pthread_mutex_init(&_mutex,NULL);
	}

	mutexlock::~mutexlock()
	{
		pthread_mutex_destroy(& _mutex);
	}

	void mutexlock::lock()
	{
		pthread_mutex_lock(& _mutex);
	}

	void mutexlock::unlock()
	{
		pthread_mutex_unlock(& _mutex);
	}

}


