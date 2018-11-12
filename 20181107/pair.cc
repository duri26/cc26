 ///
 /// @file    pair.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-09 19:41:46
 ///
#include <string>
#include <utility>
#include <iostream>
using std::cout;
using std::endl;
using std::pair;
using std::string;

void test0()
{
	pair <int,string> t (11,"hello world");
cout<<t.first<<"  "<<t.second<<endl;
}

void test1()
{
	pair<const int,string>r(33,"sony");
	cout<<r.first<<"33333"<<r.second<<endl;
}

int main(void)
{
	test0();

	test1();
	return 0;
}
