 ///
 /// @file    mutexlock.h
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-10-30 23:39:49
 ///
 //
 
#ifndef __MUTEXLOCK_H__
#define __MUTEXLOCK_H__

class mutexlock
{
	public:
		void lock();
		void unlock();
			
	private:
			static bool _sem;
};

#endif

