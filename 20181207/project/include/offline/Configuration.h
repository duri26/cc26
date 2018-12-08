 ///
 /// @file    Configuration.h
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-12-07 20:55:08
 ///

#ifndef __DICT_CONFIGURATION_H__
#define __DICT_CONFIGURATION_H__

#include <unordered_map>
#include <string>

using namespace std;

namespace dict
{


//配置文件类，单例对象
class Configuration
{
	public:
		static Configuration * getInstance();
		string getConfig(const string & word) const
		{
			auto cit = _conf.find(word);
			if (cit == _conf.end())
			{
				return string(); //什么意思
			}
			
			return cit->second; 
		}

	private:
		Configuration(const string &);
		void init(const string &);
		static void destroy();

	private:
		unordered_map<string, string> _conf;

		static Configuration * _pInstance;
};

#define getConfig(s) Configuration::getInstance()->getConfig(s)

}

#endif

