 ///
 /// @file    Configuration.h
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-29 19:55:47
 ///

#ifndef __DURI_CONFIGURATION_H__
#define __DURI_CONFIGURATION_H__

#include "Noncopyable.h"

#include <unordered_map>
#include <string>

using std::string;

namespace duri
{

class Configuration
{
	public:
		static Configuration * getInstance();
		string getConfig(const string & word)const 
		{
			auto cit = _conf.find(word);
			if(cit == _conf.end())
			{
				return string();
			}
			return cit->second;
		}

	private:
		Configuration(const string &);
		void init(const string &);
		static void destroy();

	private:
		std::unordered_map<string ,string> _conf;

		static Configuration * _pInstance;
};

#define getConfig(s)  Configuration::getInstance()->getConfig(s)

}

#endif
