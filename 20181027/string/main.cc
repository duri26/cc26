 ///
 /// @file    main.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-10-29 20:21:12
 ///
#include "string.h"

#include <iostream>
using std::cout;
using std::endl;

int main(void)
{
	string str1;
	str1.print();

	string str2="hello world";
	str2.print();

	string str3("lalala");
	str3.print();

	string str4(str3);
	//	string str4=str3;
	str4.print();

	str4=str2;
	str4.print();

	return 0;
}
