 ///
 /// @file    main.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-10-29 21:20:11
 ///
#include "stack.h"

#include <iostream>
using std::cout;
using std::endl;

int main(void)
{
	stack s;

	s.push(10);
	s.push(12);
	s.push(14);   其限制是仅允许在表的一端进行插入和删除运算。这一端被称为栈顶

cout<<"top():"<<	s.top()<<endl<<endl;
	s.pop();
cout<<"top():"<<	s.top()<<endl;

	return 0;
}

