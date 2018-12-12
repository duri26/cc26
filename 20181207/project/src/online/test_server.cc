 ///
 /// @file    test_server.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-12-12 14:54:34
 ///


#include "SpellcorrectServer.h"
#include "Configuration.h"
#include "TimerThread.h"
#include "Dictionary.h"
#include "CacheManager.h"

#include <iostream>

using namespace std;
using namespace mysp;


int main()
{

	Configuration::getInstance("../../conf/server.conf");

	Dictionary::getInstance()->initDict(getConfig("dictName"));
	Dictionary::getInstance()->initIndex(getConfig("indexName"));

	CacheManager::initCache(atoi(getConfig("pthreadNum").c_str()));

	TimerThread timeThread(CacheManager::periodicUpdateCaches,
			atoi(getConfig("cacheUpdateInitialtime").c_str()),
			atoi(getConfig("cacheUpdateIntervaltime").c_str()));

	SpellcorrectServer server;
	timeThread.start();
	server.start();
	return 0;
}

