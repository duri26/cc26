 ///
 /// @file    Configuration.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-12-08 11:44:13
 ///

#include "../../include/offline/Configuration.h"
#include "../../include/offline/Mylogger.h"

#include <stdlib.h>
#include <boost/algorithm/string.hpp>
#include <vector>
#include <iostream>
#include <fstream>

namespace dict
{

Configuration * Configuration::_pInstance;

Configuration::Configuration(const string & file)
{
	init(file);
}

Configuration * Configuration::getInstance()
{
	if(!_pInstance)
{		_pInstance =new Configuration("../conf/dict.conf");
	atexit(destroy);
}
return _pInstance;
}

void Configuration::destroy()
{
	if(_pInstance)
		delete _pInstance;
}

void Configuration::init(const string & file)
{
	std::ifstream input(file);

	if(!input)
	{
		LogError("Open config file \"%s\" failed",file.c_str());
		exit(EXIT_FAILURE);
	}
	else
	{
		LogInfo("Open config file \"%s\" success",file.c_str());
	}

	std::string line;
	std::vector<string> vec;
	while(getline(input,line))
	{
		if(!line.size())
			continue;

		boost::split(vec,line,boost::is_any_of(" \t,:")
				,boost::token_compress_on);
		_conf.emplace(vec[0],vec[1]);
	}

	input.close();
}

}

