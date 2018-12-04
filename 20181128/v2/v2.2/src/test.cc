 ///
 /// @file    test.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-29 21:14:02
 ///

#include "Configuration.h"
#include "Mylogger.h"
#include "DictProducer.h"

#include <iostream>
using std::cout;
using std::endl;

int main(void)
{
	cout<<duri::getConfig("dictionarySourceFile")<<endl;

	duri::DictProducer dict;
	dict.buildEnDict();
	dict.buildIndex();
	dict.store();

	return 0;
}
