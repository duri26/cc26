 ///
 /// @file    cachemanager.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-12-06 16:15:01
 ///

#include "Mylogger.h"
#include "cachemanager.h"
#include "Configuration.h"

using namespace duri;

namespace wd
{

vector<Cache> CacheManager::_cacheList;

void CacheManager::initCache(size_t size){	
	Cache cache(atoi(getConfig("cacheCapacity").c_str()));
	cache.readFromFile(getConfig("cacheStoreFile"));
	for (size_t i = 0; i != size; ++i){
		_cacheList.push_back(cache);
	}
}

Cache & CacheManager::getCache(size_t idx){
	return _cacheList[idx];
}

void CacheManager::periodicUpdateCahces(){
	cout << "update caches" << endl;
	for (size_t i = 1; i != _cacheList.size(); ++i){
		_cacheList[0].update(_cacheList[i]);
	}

	for (size_t i = 1; i != _cacheList.size(); ++i){
		_cacheList[i].update(_cacheList[0]);
	}

	for (size_t i = 0; i != _cacheList.size(); ++i){
		_cacheList[i].getRecentlySet().clear();
	}

	_cacheList[0].writeToFile(getConfig("cacheStoreFile"));

	LogInfo("caches update success");
}

}
