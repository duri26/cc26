 ///
 /// @file    mutexlock.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-10-30 23:36:46
 ///
#include "mutexlock.h"

bool mutexlock:: _sem=1;

void mutexlock::lock()
{
	while(!_sem)
		;
	_sem =0;
}



void mutexlock::unlock()
{
	_sem=1;
}	
