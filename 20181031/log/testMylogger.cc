 ///
 /// @file    testMylogger.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-11-01 11:35:15
 ///
 
#include "Mylogger.h"
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;


void test0(void)
{
	Mylogger::getInstance()->warn("this is warn msg");
	Mylogger::getInstance()->info("this is info msg");
	Mylogger::getInstance()->error("this is error msg");
	Mylogger::getInstance()->debug("this is debug msg");
}

void test1(void) {
	cout << __FILE__ << endl;
	cout << __FUNCTION__ << endl;
	cout << __LINE__ << endl;
}

void test2(void)
{
	Mylogger::getInstance()->warn(prefix("this is warn msg"));
	Mylogger::getInstance()->info(prefix("this is info msg"));
	Mylogger::getInstance()->error(prefix("this is error msg"));
	Mylogger::getInstance()->debug(prefix("this is debug msg"));
}

void test3(void) {
	LogWarn("this is warn msg ");
	LogInfo("this is info msg");
	LogError("this is error msg");
	LogDebug("this is debug msg");
}
int main(void)
{
	//test0();

	//test2();
	test3();

	return 0;
}