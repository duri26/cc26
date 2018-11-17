 ///
 /// @file    testthread.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-15 17:53:44
 ///


#include "mutexlock.h"
#include "condition.h"

#include <iostream>
using std::cout;
using std::endl;
using namespace wd;

int gNumber = 0;
MutexLock mutex;
//MutexLock mutex2 = mutex;//error
Condition cond(mutex);
bool flag = true;

void * func1(void * arg)
{// 当flag 为true时，执行++操作
	int cnt = 10;
	while(cnt--) {
		MutexLockGuard autolock(mutex);
	//	mutex.lock();
		if(flag == false ) {
			cond.wait();
		}

		++gNumber;
		cout << "SubThread1: " << pthread_self() 
			 << ": gNumber = " << gNumber << endl;
		flag = false;
		cond.notify();
//		mutex.unlock();
	}

	return NULL;
}


void * func2(void * arg)
{// 当flag 为false时，执行++操作
	int cnt = 10;
	while(cnt--) {
		//mutex.lock();
		MutexLockGuard autolock(mutex);
		if(flag == true) {
			cond.wait();
		} 
		++gNumber;
		cout << "SubThread2: " << pthread_self() 
			 << ": gNumber = " << gNumber << endl;
		flag = true;
		cond.notify();
	//	mutex.unlock();
	}
	
	return NULL;
}

 
int main(void)
{
	pthread_t pth1, pth2;
	pthread_create(&pth1, NULL, func1, NULL);
	pthread_create(&pth2, NULL, func2, NULL);

	pthread_join(pth1, NULL);
	pthread_join(pth2, NULL);
	
	return 0;
}

