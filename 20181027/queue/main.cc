 ///
 /// @file    main.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-10-30 00:01:28
 ///
#include "queue.h"
 
#include <iostream>
using std::cout;
using std::endl;

int main(void)
{
	queue q;

	cout << q.empty() << endl;
	for (int i = 0; i < 10; i++)
	{
		q.push(i + 1);
	}

	cout << q.front() << endl;
	cout << q.back() << endl;
	cout << q.full() << endl<<endl;

	q.pop();
	cout << q.full() << endl;

	cout << q.front() << endl;
	cout << q.back() << endl;
	return 0;
}

