 ///
 /// @file    mian.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-29 22:17:08
 ///

#include <string.h>

#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;

int main(void)
{
	string a = " ";// 类的大小
	char b = ' ';
//	char c = " ";

	//cout<<"a"<<a<<":"<<sizeof(a)<<endl;
	cout<<"a"<<a<<":"<<a.size()<<endl;//a的大小，用size()

	cout<<"b"<<b<<":"<<sizeof(b)<<endl;

	return 0;
}
