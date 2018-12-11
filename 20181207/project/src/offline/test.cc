 ///
 /// @file    test.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-12-10 16:41:11
 ///

#include "../../include/offline/Configuration.h"
#include "../../include/offline/Mylogger.h"
#include "../../include/offline/DictProducer.h"
#include "../../include/offline/SplitToolCppJieba.h"

#include <unistd.h>

#include <iostream>

using std::cout;
using std::endl;

int main(void)
{
	dict::Configuration::getInstance();
	dict::SplitToolCppJieba jieba;
	dict::DictProducer dict(&jieba);
	dict.buildDict();
	dict.buildIndex();
	dict.store();

	return 0;
}

