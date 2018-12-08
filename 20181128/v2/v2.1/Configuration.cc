 ///
 /// @file    Configuration.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-29 20:53:50
 ///

#include "Configuration.h"
#include "Mylogger.h"

#include <stdlib.h>
#include <boost/algorithm/string.hpp>
#include <vector>
#include <iostream>
#include <fstream>

namespace duri
{

Configuration * Configuration::_pInstance;

Configuration::Configuration(const string & file)
{
	init(file);
}

Configuration * Configuration::getInstance()
{
	if(!_pInstance)
{
	_pInstance = new Configuration("../conf/dict.conf");
	atexit(destroy);
}
return _pInstance;
}

void Configuration::destroy()
{
	if(_pInstance)
	{
		delete _pInstance;
	}

}

void Configuration::init(const string & file)
{
	std::ifstream input(file);

	if(!input)
	{
		LogError("  Open config file \"%s\" failed",file.c_str());
		exit(EXIT_FAILURE);
	}
	else 
	{
		LogInfo("  Open config file \"%s\" success", file.c_str());
	}

    string line;
	std::vector <string> vec;
	while(getline(input,line))
	{
		boost::split(vec,line,boost::is_any_of(" \t,: ")//分词，is_any_of(" \t,: ") 分词的关键"空格，tab,:,
				,boost::token_compress_on); //   token_compress_on防止将两个, ,其中一个放在单词里；
     _conf.emplace(vec[0],vec[1]);// 类似insert
	}

	input.close();
}

}

