///
/// @file    main.cc
/// @author  duri(1197010670@qq.com)
/// @date    2018-10-30 23:42:21
///
#include "mutexlock.h"
#include <pthread.h>
#include <stdio.h>
#define N 1000000

//#include <iostream>
//using std::cout;
//using std::endl;
//g++ main.cc mutexlock.cc -pthread
//注意 要指出方向；
typedef struct
{
	mutexlock mutex;
	int sum;
}Data;

void *pthreadfun(void *p)
{
	Data *p1 = (Data *)p;
	for (int i = 0; i < N; ++i)
	{
		p1->mutex.lock();
//		p1->++sum;注
		p1->sum++;
		p1->mutex.unlock();
	}

	pthread_exit(NULL);
}

int main(void)
{
	pthread_t thdid1, thdid2;
	Data data;
	data.sum = 0;

	pthread_create(&thdid1, NULL, pthreadfun, &data);
	pthread_create(&thdid2, NULL, pthreadfun, &data);

	for (int i = 0; i < N; ++i)
	{
		data.mutex.lock();
		++data.sum;
		data.mutex.unlock();
	}

	pthread_join(thdid1, NULL);
	pthread_join(thdid2, NULL);

	printf("sum = %d\n",data.sum);
	return 0;
}

