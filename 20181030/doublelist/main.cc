 ///
 /// @file    main.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-10-31 16:01:27
 ///
#include "doublelist.h"

#include <iostream>
using std::cout;
using std::endl;

int main(void )
{
	List l;
	for(int i=0;i<10;++i)
	{
		l.push_back(i+1);
	}
	cout << "size="<<l.size()<<endl;
    l.insert(0,0);
	l.insert(11, 11);
	l.insert(22, 22);
	l.insert(33, 33);
	l.display();

	l.push_front(0);
	l.push_front(0);

	l.display();
	l.erase(0);
	l.erase(5);
	l.erase(12);
	l.display();

	for (int i = 0; i < 6;++i)
{
		l.pop_back();
	}
	cout << "size = " << l.size() << endl;
	for (int i = 0; i < 6; ++i)
{
		l.pop_front();
	}

	cout << "empty = " << l.empty() << endl;

	return 0;
}

