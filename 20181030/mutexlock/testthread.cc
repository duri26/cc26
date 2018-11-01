 ///
 /// @file    testthread.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-10-31 20:58:13
 ///
#include "mutexlock.h"
#include "condition.h"
#define N 10

#include <iostream>
using std::cout;
using std::endl;
using namespace wd;

int gnumber=0;
mutexlock mutex;

condition cond(mutex);
bool flag=true;

void * func1(void * arg )
{
	int cnt =N;
	while(cnt--)
	{
		mutexlockguard autolock(mutex);
		if(flag ==false)
		{
			cond.wait();
		}

		++gnumber;
		cout<<"subthread1:"<<pthread_self()
			<<": gnumber=" <<gnumber<<endl;
flag=false;
		cond.notify();
	}
	return NULL ;
}



void * func2(void *arg )
{
	int cnt =N;
	while(cnt--)
	{
		mutexlockguard autolock(mutex);
		if(flag ==true)
		{
			cond.wait();
		}

		++gnumber;
		cout<<"subthread2:"<<pthread_self()
			<<": gnumber=" <<gnumber<<endl;
flag=true; //注意
		cond.notify();
	}
	return NULL ; 
}

int main(void )
{
	pthread_t pth1,pth2;
	pthread_create(&pth1,NULL,func1,NULL);
	pthread_create(&pth2,NULL,func2,NULL);

	pthread_join(pth1,NULL);
	pthread_join(pth2,NULL);

	return 0;
}

