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
	if(_pInstance)
		_pInstance =new 
