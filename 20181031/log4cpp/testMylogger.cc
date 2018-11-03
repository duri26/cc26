 ///
 /// @file    testMylogger.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-01 19:57:38
 ///
#include "Mylogger.h"

#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;

void test0(void)
{
	Mylogger::getInstance()->warn("warn msg");
	Mylogger::getInstance()->info("info msg");
	Mylogger::getInstance()->error("error msg");
	Mylogger::getInstance()->debug("debug msg");
}

void test1(void)
{
	cout<< __FILE__<<endl;
	cout<<__FUNCTION__<<endl;
	cout<<__LINE__<<endl;
}

void test2(void)
{
	Mylogger::getInstance()->warn(prefix("this is warn msg"));
	Mylogger::getInstance()->info(prefix("this is info msg"));
	Mylogger::getInstance()->error(prefix("this is error msg"));
	Mylogger::getInstance()->debug(prefix("this is debug msg"));
}

void test3(void)
{
	LogWarn(" log warn");
	LogInfo(" log info");
	LogError("log error");
	LogDebug("log debug");
}

void test4(int a)
{
	char buf[1000]={0};
	sprintf(buf,"hello // world * %#x",a);
	LogInfo(buf);
};


int main(void)
{
//test0();

	//test1();
//test2();	
	//	test3();
test4(9);
return 0;
}
