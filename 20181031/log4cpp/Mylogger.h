 ///
 /// @file    Mylogger.h
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-01 14:20:46
 ///
#ifndef __WD_MYLOGGER_H__
#define __WD_MYLOGGER_H__

#include <log4cpp/Category.hh>
#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;
using namespace log4cpp;

class Mylogger
{
	public:
		static Mylogger * getInstance();
		static void shutdown();

		void info(const char * msg);
		void warn(const char * msg);
		void error(const char * msg);
		void debug(const char * msg);

	private:
		Mylogger();
		~Mylogger();

	private:
		Category  & _root;
		static Mylogger * _pInstance;
};



#define prefix(msg)	string().append("[").append(__FILE__)\
	.append("-").append(__FUNCTION__)\
	.append("-").append(std::to_string(__LINE__))\
	.append("] ").append(msg).c_str()

#define LogInfo(msg) Mylogger::getInstance()->info(prefix(msg))
#define LogWarn(msg) Mylogger::getInstance()->warn(prefix(msg))
#define LogError(msg) Mylogger::getInstance()->error(prefix(msg))
#define LogDebug(msg) Mylogger::getInstance()->debug(prefix(msg))

#endif 
