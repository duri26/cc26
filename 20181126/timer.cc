 ///
 /// @file    timer.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-27 23:38:02
 ///

#include "timer.h"

#include <unistd.h>
#include <errno.h>
#include <poll.h>
#include <sys/timerfd.h>

#include <iostream>
using std::cout;
using std::endl;

using namespace wd;

Timer::Timer(TimerCallback && cb,int initialTime,int intervalTime)
	:
